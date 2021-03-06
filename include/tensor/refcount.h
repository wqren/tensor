// -*- mode: c++; fill-column: 80; c-basic-offset: 2; indent-tabs-mode: nil -*-
/*
    Copyright (c) 2010 Juan Jose Garcia Ripoll

    Tensor is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published
    by the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Library General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef TENSOR_REFCOUNT_H
#define TENSOR_REFCOUNT_H

#include <cstring>
#include <algorithm>

namespace tensor {

/**A reference counting object. This object keeps a pointer and the number
   of references to it which are read/only or read/write. A pointer can
   be shared by multiple read/only or by multiple read/write references,
   but if there are read/write references, only one object can be tagged
   as read/only reference.
*/
template<typename elt_t>
class SharedPtr {
public:
  /** Reference counter for null pointer */
  SharedPtr();
  /** Reference count a given data */
  SharedPtr(elt_t *data, size_t size);

  /** Create a new reference object with the same data and only 1 ro reference. */
  SharedPtr *clone();
  /** Add a read/only reference. */
  SharedPtr<elt_t> *ro_reference();
  /** Add a read/write reference. */
  SharedPtr<elt_t> *rw_reference();
  /** Eliminate a read/only reference. */
  void ro_dereference();
  /** Eliminate a read/write reference. */
  void rw_dereference();
  /** An object is read/only if other references expect it not to change. */
  bool read_only() { return ro_references() > 1; }
  /** An object can mutate if there are references that can change it. */
  bool can_mutate() { return rw_references() > 0; }
  /** Return number of read/only references. */
  int ro_references() { return ro_references_; }
  /** Return number of read/write references. */
  int rw_references() { return rw_references_; }

  /** Amount of data allocated. */
  size_t size() { return size_; }
  /** Return pointer. */
  elt_t *begin() { return data_; }
  /** Return end pointer. */
  elt_t *end() { return begin() + size(); }

private:

  SharedPtr(const SharedPtr<elt_t> &p); // Prevents copy constructor

  void check_delete();

  elt_t *data_;
  size_t size_;
  int ro_references_, rw_references_;
};

template<typename elt_t> class RefPointerView;

/**A reference counting pointer. This is a pointer that keeps track of whether
   the same pointer is shared by other structures, and when the total number of
   references drops to zero, it destroys the pointed object.

   We use this pointer to implement vectors of numbers. Two vectors can share
   the same data. Whenever one of the vectors pointing to this data is
   destroyed, the number of references drops by one. When all vectors pointing
   to the same data are destroyed, the data is, as well.

   \ingroup Internals
*/
template<class value_type>
class RefPointer {
public:
  typedef value_type elt_t; ///< Type of data pointed to

  /** Empty reference */
  RefPointer();
  /** Allocate a pointer of s bytes. */
  RefPointer(size_t new_size);
  /** Copy constructor that increases the reference count. */
  RefPointer(const RefPointer<elt_t> &p);
  /** Reference count a given data */
  RefPointer(elt_t *data, size_t size);

  /** Destructor that deletes no longer reference data. */
  ~RefPointer();

  /** Copy a pointer increasing the reference count. */
  RefPointer<elt_t> &operator=(const RefPointer<elt_t> &p);

  /** Retreive the pointer without caring for references (unsafe). */
  elt_t *begin() { appropiate(); return ref_->begin(); }
  /** Retreive the pointer without caring for references (unsafe). */
  const elt_t *begin() const { return ref_->begin(); }
  /** Retreive the pointer without caring for references (unsafe). */
  const elt_t *begin_const() const { return ref_->begin(); }
  /** Retreive the pointer without caring for references (unsafe). */
  const elt_t *end_const() const { return ref_->end(); }
  /** Retreive the pointer without caring for references (unsafe). */
  const elt_t *end() const { return ref_->end(); }
  /** Retreive the pointer without caring for references (unsafe). */
  elt_t *end() { appropiate(); return ref_->end(); }

  /** Size of pointed-to data. */
  size_t size() const { return ref_->size(); }

  /** Reference counter */
  size_t ref_count() const { return ref_->ro_references() + ref_->rw_references(); }
  /** Reference counter */
  bool other_references() const { return ref_->read_only() > 1; }
  /** Ensure that we have a unique copy of the data. If the pointer has more
      than one reference, a fresh new copy of the data is created.
  */
  void appropiate();

  /** Replace the pointer with newly allocated data. */
  void reallocate(size_t new_size);
  /** Set to NULL */
  void reset() { reset(0, 0); }
  /** Set to some pointer */
  void reset(elt_t *p, size_t new_size = 1);

  friend class RefPointerView<elt_t>;

private:
  SharedPtr<elt_t> *rw_reference() const;

  mutable SharedPtr<elt_t> *ref_; // Pointer to data we reference or NULL
};

/**A view on a reference counting pointer. This object shares the data with a
   RefPointer<elt_t> object, allowing external modification of the data
   owned by the latter.

   This object is used to implement VectorView, TensorDiag, etc.

   \ingroup Internals
*/

template<typename value_type>
class RefPointerView {
public:
  typedef value_type elt_t; ///< Type of data pointed to

  /** Copy constructor that increases the reference count. */
  RefPointerView(const RefPointer<elt_t> &p);

  /** Propagate view. */
  RefPointerView(const RefPointerView<elt_t> &v);

  /** Destructor that deletes no longer reference data. */
  ~RefPointerView();

  /** Retreive the pointer without caring for references (unsafe). */
  elt_t *begin() { return ref_->begin(); }
  /** Retreive the pointer without caring for references (unsafe). */
  const elt_t *begin() const { return ref_->begin(); }
  /** Retreive the pointer without caring for references (unsafe). */
  const elt_t *begin_const() const { return ref_->begin(); }
  /** Retreive the pointer without caring for references (unsafe). */
  const elt_t *end_const() const { return ref_->end(); }
  /** Retreive the pointer without caring for references (unsafe). */
  const elt_t *end() const { return ref_->end(); }
  /** Retreive the pointer without caring for references (unsafe). */
  elt_t *end() { return ref_->end(); }

  /** Size of pointed-to data. */
  size_t size() const { return ref_->size(); }

  /** Reference counter. */
  size_t ref_count() const { return ref_->ro_references() + ref_->rw_references(); }

private:
  RefPointerView(); // Deactivated
  RefPointer<elt_t> &operator=(const RefPointer<elt_t> &p); // Deactivat

  SharedPtr<elt_t> *rw_reference() const;

  mutable SharedPtr<elt_t> *ref_; // Pointer to data we reference or NULL
};

}; // namespace

#include <tensor/detail/refcount.hpp>

#endif /* !REFCOUNT_REFCOUNT_H */
