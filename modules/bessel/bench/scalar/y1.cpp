//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/bessel/include/y1.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <cmath>



//////////////////////////////////////////////////////////////////////////////
// Scalar Runtime benchmark for functor<y1_> from bessel
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::y1_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) , T(V2))


NT2_TIMING(nt2::tag::y1_,(RS(float,0.0f,100.0f)))
NT2_TIMING(nt2::tag::y1_,(RS(double,0.0,100.0)))
NT2_TIMING(nt2::tag::y1_,(RS(float,0.0f,2.0f)))
NT2_TIMING(nt2::tag::y1_,(RS(double,0.0,2.0)))

#undef RS
