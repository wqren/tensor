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

#define TENSOR_LOAD_IMPL
#include <tensor/tensor.h>

namespace tensor {

  // Explicit instantiation
  template const Tensor<cdouble> kron(const Tensor<cdouble> &s1,
                                      const Tensor<cdouble> &s2);
  template const Tensor<cdouble> kron2(const Tensor<cdouble> &s1,
                                       const Tensor<cdouble> &s2);
  template const Tensor<cdouble> kron2_sum(const Tensor<cdouble> &s1,
                                           const Tensor<cdouble> &s2);

} // namespace tensor
