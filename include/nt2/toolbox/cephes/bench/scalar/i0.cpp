//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/cephes/include/i0.hpp>
#include <nt2/sdk/unit/benchmark.hpp>

//////////////////////////////////////////////////////////////////////////////
// Runtime benchmark for functor<i0_> from cephes
//////////////////////////////////////////////////////////////////////////////
using nt2::cephes::i0_;

//////////////////////////////////////////////////////////////////////////////
// bench/scalar
// E.G:
// NT2_TIMING( i0_ , ((nt2::uint32_t, -10, 10)) ) 
//           )
//////////////////////////////////////////////////////////////////////////////