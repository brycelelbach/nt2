//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EULER_FUNCTION_SIMD_COMMON_STIRLING_HPP_INCLUDED
#define NT2_TOOLBOX_EULER_FUNCTION_SIMD_COMMON_STIRLING_HPP_INCLUDED
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/pow.hpp>
#include <nt2/include/functions/polevl.hpp>
#include <nt2/include/functions/fma.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/exp.hpp>


namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<stirling_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::is_real_convertible<A0>{}; 
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute stirling(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<stirling_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};


    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (3, (float, double,arithmetic_))
    )
    NT2_FUNCTOR_CALL_EVAL_IF(1,       float)
    {
      typedef typename meta::scalar_of<A0>::type  sA0; 
      static const A0 SQTPI = splat<A0>(2.50662827463100050242); /* sqrt( 2 pi ) */
      static const boost::array<sA0, 3 > STIR = {{
	  -2.705194986674176E-003f,
	  3.473255786154910E-003f,
	  8.333331788340907E-002f,
	}};
      static const A0 MAXSTIR = splat<A0>(26.77);
      
      A0 w = rec(a0);
      w = fma(w, polevl( w, STIR), One<A0>());
      A0 r = Nan<A0>();
      A0 y = exp( -a0 );
      A0 test = isgt(a0, MAXSTIR);
      const A0 v = pow( a0, fma(Half<A0>(), a0, - Quarter<A0>()) );
      y *= v;
      y *= v;
      y *= SQTPI * w;
      return y;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,       double)
    {
      typedef typename meta::scalar_of<A0>::type  sA0; 
      static const A0 MAXSTIR = splat<A0>(143.01608); 
      static const boost::array<sA0, 5 > STIR = {{
	  7.87311395793093628397E-4,
	  -2.29549961613378126380E-4,
	  -2.68132617805781232825E-3,
	  3.47222221605458667310E-3,
	  8.33333333333482257126E-2,
	}};
      static const A0 SQTPI =  splat<A0>(2.50662827463100050242E0);
      A0 w = rec(a0);
      w = fma(w, polevl( w, STIR), One<A0>());
      A0 y = exp(-a0);
      const A0 v = pow(a0, fma(Half<A0>(), a0, - Quarter<A0>())); 
      y *= v;
      y *= v;
      y *= SQTPI*w;
      return y;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,       arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type;
      return stirling(type(a0));
    }

  };
} }

      
#endif