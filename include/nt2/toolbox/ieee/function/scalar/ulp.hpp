//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_ULP_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_ULP_HPP_INCLUDED
#include <nt2/sdk/constant/properties.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_bits.hpp>

#include <nt2/include/functions/predecessor.hpp>
#include <nt2/include/functions/min.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/abs.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for ulp

  /////////////////////////////////////////////////////////////////////////////
  // Compute ulp(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<ulp_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::arithmetic(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      A0,
      (2, (real_,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,       real_)
    {
      typedef typename meta::as_integer<A0,signed>::type int_type;
      if (iseqz(a0)) return Smallestposval<A0>();
      const A0 x = abs(a0);
      if (x == Inf<A0>()) return  Valmax<A0>()-predecessor(Valmax<A0>());
      typename meta::as_bits<A0>::type aa = {x},  bb = aa;
      --bb.bits;
      ++aa.bits;
      return nt2::min(x-bb.value, aa.value-x);
      // 	 const A0 pred = predecessor(x);
      // 	 return (x == Inf<A0>()) ? pred-predecessor(x) : min(dist(pred, x), dist(x, successor(x)));
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
       return One<A0>();
    }
  };
} }


      
#endif