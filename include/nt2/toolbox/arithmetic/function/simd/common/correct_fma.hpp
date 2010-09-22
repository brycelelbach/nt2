//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_CORRECT_FMA_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_CORRECT_FMA_HPP_INCLUDED
#include <boost/fusion/tuple.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/two_prod.hpp>
#include <nt2/include/functions/two_add.hpp>


namespace nt2 { namespace functors
{
  //  no special validate for correct_fma

  /////////////////////////////////////////////////////////////////////////////
  // Compute correct_fma(const A0& a0, const A0& a1, const A0& a2)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<correct_fma_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0,A0,A0)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL_DISPATCH(
      3,
      typename nt2::meta::scalar_of<A0>::type,
      (2, (real_,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(3,       real_)
    {
      A0 p, rp, s, rs;
      boost::fusion::tie(p, rp) = two_prod(a0, a1);
      boost::fusion::tie(s, rs) = two_add(p, a2);
      return s+(rp+rs);
    }
    NT2_FUNCTOR_CALL_EVAL_IF(3,       arithmetic_)
    {
      return a0*a1+a2;
    }
  };
} }

      
#endif