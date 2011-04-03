//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/arithmetic/include/subs.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<subs_> from arithmetic
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::subs_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef int8_t T;
  NT2_TIMING(nt2::tag::subs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n2 {
  typedef int16_t T;
  NT2_TIMING(nt2::tag::subs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n3 {
  typedef int32_t T;
  NT2_TIMING(nt2::tag::subs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n4 {
  typedef int64_t T;
  NT2_TIMING(nt2::tag::subs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n5 {
  typedef uint8_t T;
  NT2_TIMING(nt2::tag::subs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n6 {
  typedef uint16_t T;
  NT2_TIMING(nt2::tag::subs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n7 {
  typedef uint32_t T;
  NT2_TIMING(nt2::tag::subs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}
namespace n8 {
  typedef uint64_t T;
  NT2_TIMING(nt2::tag::subs_,(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4)))(RS(T,3*(nt2::Valmin<T>()/4),3*(nt2::Valmax<T>()/4))))
}

#undef RS
