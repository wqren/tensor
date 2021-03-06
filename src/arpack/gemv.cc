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

#ifndef TENSOR_GEMV_CC
#define TENSOR_GEMV_CC

#ifdef TENSOR_USE_ESSL
#include <essl.h>
#endif
#include <tensor/tensor_blas.h>

namespace blas {

  inline void gemv(char trans, integer m, integer n, const double alpha,
		   const double a[], integer lda, const double x[], integer incx,
		   const double &beta, double y[], integer incy)
  {
#ifdef TENSOR_USE_ESSL
    dgemv(&trans, m, n, alpha, a, lda, x, incx, beta, y, incy);
#else
    cblas_dgemv(CblasColMajor, char_to_op(trans), m, n,
		alpha, a, lda, x, incx, beta, y, incy);
#endif
  }

  inline void gemv(char trans, integer m, integer n, const tensor::cdouble &alpha,
		   const tensor::cdouble *a, integer lda, const tensor::cdouble *x,
		   integer incx, const tensor::cdouble &beta, tensor::cdouble *y,
		   integer incy)
  {
#ifdef TENSOR_USE_ESSL
    zgemv(&trans, m, n, alpha, a, lda, x, incx, beta, y, incy);
#else
    cblas_zgemv(CblasColMajor, char_to_op(trans), m, n,
		&alpha, a, lda, x, incx, &beta, y, incy);
#endif
  }

} // namespace blas

#endif // TENSOR_GEMV_CC
