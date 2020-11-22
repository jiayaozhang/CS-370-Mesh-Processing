// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "avg_edge_length.h"
#include "edges.h"

#include <vector>

template <typename DerivedV, typename DerivedF>
IGL_INLINE double igl::avg_edge_length(
  const Eigen::MatrixBase<DerivedV>& V,
  const Eigen::MatrixBase<DerivedF>& F)
{
  typedef typename DerivedF::Scalar Index;
  Eigen::Matrix<Index, Eigen::Dynamic, 2> E;

  igl::edges(F, E);

  double avg = 0;

  for (unsigned i=0;i<E.rows();++i)
  {
    avg += (V.row(E(i,0)) - V.row(E(i,1))).norm();
  }

  return avg / (double) E.rows();
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template double igl::avg_edge_length<Eigen::Matrix<double, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&);
template double igl::avg_edge_length<Eigen::Matrix<double, -1, 3, 0, -1, 3>, Eigen::Matrix<int, -1, 3, 0, -1, 3> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3> > const&, Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3> > const&);
// generated by autoexplicit.sh
#endif
