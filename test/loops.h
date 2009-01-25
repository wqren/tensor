// -*- mode: c++; fill-column: 80; c-basic-offset: 2; indent-tabs-mode: nil -*-
//
// Copyright 2008, Juan Jose Garcia-Ripoll
//

#ifndef TENSOR_TEST_LOOPS_H
#define TENSOR_TEST_LOOPS_H

#include <algorithm>
#include <gtest/gtest.h>
#include <tensor/rand.h>
#include <tensor/tensor.h>
#include <tensor/io.h>

#define EPSILON 1e-14

#ifdef NDEBUG
#define ONLY_IN_DEBUG(x)
#else
#define ONLY_IN_DEBUG(x) x
#endif

namespace tensor_test {

using namespace tensor;

/*
 * Verifies that the tensor that has been passed to the routine has
 * not been reallocated.
 */
template<class Tensor>
void unchanged(const Tensor &t1, const Tensor &t2, size_t expected_refs = 2) {
  if ((t1.size() + t2.size()) == 0)
    return;
  EXPECT_EQ(t1.begin_const(), t2.begin_const());
  EXPECT_EQ(expected_refs, t1.ref_count());
  EXPECT_EQ(expected_refs, t2.ref_count());
}

/*
 * Verifies that the tensor that has been passed to the routine has
 * not been reallocated.
 */
template<class Tensor>
void unique(const Tensor &t) {
  if (t.size()) {
    EXPECT_EQ(1, t.ref_count());
  }
}

/*
 * Approximately equal tensors.
 */
template<class Tensor>
bool approx_eq(const Tensor &A, const Tensor &B, double epsilon = EPSILON)
{
  if (A.rank() == B.rank()) {
    if (A.dimensions() == B.dimensions()) {
      for (typename Tensor::const_iterator a = A.begin(), b = B.begin();
           a!= A.end(); ++a,++b)
        {
          if (abs(*a - *b) > epsilon*std::max(abs(*a),abs(*b))) {
            std::cout << *a << ' ' << *b << ' ' << abs(*a - *b) << std::endl;
            return false;
          }
        }
      return true;
    }
  }
  return false;
}

/*
 * Test over integers.
 */
inline void
test_over_integers(int min, int max, void test(int))
{
    for (; min <= max; min++) {
      test(min);
    }
}

/*
 * Creates a vector of random dimensions.
 */
inline Indices random_dimensions(int rank, int max_dim) {
  Indices dims(rank);
  for (int i = 0; i < rank; i++) {
    dims.at(i) = rand<int>(0, max_dim+1);
  }
  return dims;
}

template<typename elt_t>
void
test_over_fixed_rank_tensors(void test(Tensor<elt_t> &t), int rank,
                             int max_dimension = 10) {
  //
  // Test over random dimensions
  //
  Indices dims(rank);
  std::fill(dims.begin(), dims.end(), 0);
  bool goon = true;
  while (goon) {
    Tensor<elt_t> data(dims);
    // Make all elements different to make accurate comparisons
    for (tensor::index i = 0; i < data.size(); i++)
      data.at(i) = i;
    test(data);
    goon = false;
    for (int i = 0; i < rank; i++) {
      if (++dims.at(i) < max_dimension) {
        goon = true;
        break;
      }
      dims.at(i) = 0;
    }
  }
}

/*
 * Test over all tensor sizes and ranks, randomly.
 */
template<typename elt_t>
void
test_over_all_tensors(void test(Tensor<elt_t> &t), int max_rank = 4,
                      int max_dimension = 10) {
  for (size_t rank = 0; rank <= max_rank; rank++) {
    char rank_string[] = "rank:      ";
    sprintf(rank_string, "rank: %d", rank);
    SCOPED_TRACE(rank_string);
    test_over_fixed_rank_tensors(test, rank, max_dimension);
  }
}

template<typename elt_t>
void
test_over_tensors(void test(Tensor<elt_t> &t), int max_rank = 4,
                  int max_dimension = 10, int max_times = 15) {
  for (size_t rank = 0; rank <= max_rank; rank++) {
    char rank_string[] = "rank:      ";
    sprintf(rank_string, "rank: %d", rank);
    SCOPED_TRACE(rank_string);
    //
    // Test over random dimensions
    //
    for (int times = 0; times < max_times; times++) {
      Tensor<elt_t> data(random_dimensions(rank, max_dimension));
      data.randomize();
      test(data);
    }
    //
    // Forced tests over empty tensors
    //
    for (int times = 0; times < rank; times++) {
      Tensor<elt_t> data(random_dimensions(rank, max_dimension));
      data.at(times) = 0;
      data.randomize();
      test(data);
    }
  }
}

class DimensionsProducer {
public:
  DimensionsProducer(const Indices &d) : base_indices(d), counter(13) {}

  operator bool() const { return counter >= 14; }
  int operator++() { counter++; }

  Indices operator*() const {
    Tensor<double> P;
    switch (counter) {
      // 1D Tensor<elt_t>
    case 1: P = Tensor<double>(d(0)*d(1)*d(2)*d(3)); break;
      // 2D Tensor<elt_t>
    case 2: P = Tensor<double>(d(0),d(1)*d(2)*d(3)); break;
    case 3: P = Tensor<double>(d(0)*d(1),d(2)*d(3)); break;
    case 4: P = Tensor<double>(d(0)*d(1)*d(2),d(3)); break;
    case 5: P = Tensor<double>(d(3),d(0)*d(1)*d(2)); break;
    case 6: P = Tensor<double>(d(2)*d(3),d(0)*d(1)); break;
      // 3D Tensor<elt_t>
    case 7: P = Tensor<double>(d(0),d(1),d(2)*d(3)); break;
    case 8: P = Tensor<double>(d(0)*d(1),d(2),d(3)); break;
    case 9: P = Tensor<double>(d(3)*d(2),d(0),d(1)); break;
      // 4D Tensor<elt_t>
    case 10: P = Tensor<double>(d(0),d(1),d(2),d(3)); break;
    case 11: P = Tensor<double>(d(3),d(1),d(2),d(0)); break;
    case 12: P = Tensor<double>(d(1),d(0),d(3),d(2)); break;
    case 13: P = Tensor<double>(d(2),d(0),d(3),d(1)); break;
    }
    return P.dimensions();
  }

private:
  Indices::elt_t d(int which) const {
    if (which >= base_indices.size()) {
      return 1;
    } else {
      return base_indices[which];
    }
  }

  Indices base_indices;
  int counter;
};

} // namespace tensor_test

#endif /* !TENSOR_TEST_LOOPS_H */
