//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_XOP_ABS_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_XOP_ABS_HPP_INCLUDED
tag::sse_
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/meta/strip.hpp>

#include <nt2/include/functions/details/simd/sse/ssse3/abs.hpp>

namespace nt2 { namespace functors
{
  //  no special validate for abs

  template<class Extension,class Info>
  struct call<abs_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (3, (real_,signed_,unsigned_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,real_)     { return b_notand(Mzero<A0>(),a0);   }
    NT2_FUNCTOR_CALL_EVAL_IF(1,signed_)
    {
 //      typedef typename meta::scalar_of<A0>::type sctype;		
//       typedef typename simd::native<sctype, tag::sse_ >  svtype;	
//       svtype a00 = { _mm256_extractf128_si256(a0, 0)};			
//       svtype a01 = { _mm256_extractf128_si256(a0, 1)};			
//       A0 that = { _mm256_insertf128_si256(that,nt2::abs(a00), 0)};		
//       that =  _mm256_insertf128_si256(that,nt2::abs(a01), 1);
       NT2_XOP_JOIN128INT1(that, nt2::abs); 
       return that;
    }	
    NT2_FUNCTOR_CALL_EVAL_IF(1,unsigned_) { return a0;                           }
  };
} }

#endif