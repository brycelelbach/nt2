//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_EXP_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_EXP_HPP_INCLUDED

namespace nt2 { namespace functors
{
  extern "C"{
    extern double exp_rn ( double );
    extern double exp_rd ( double );
    extern double exp_rz ( double );
    extern double exp_ru ( double );
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute exp(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Rounding, class Info>
  struct call<crlibm::exp_<Rounding>,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH( 1, A0, (2, (double,arithmetic_)) )
    template<class A0, class R> struct inner_exp;
    NT2_CRLIBM_INNER_STRUCT(rn, exp, rn)
    NT2_CRLIBM_INNER_STRUCT(rd, exp, rd)
    NT2_CRLIBM_INNER_STRUCT(ru, exp, ru)
    NT2_CRLIBM_INNER_STRUCT(rz, exp, rd)
    NT2_FUNCTOR_CALL_EVAL_IF(1, double)
      {return inner_exp<A0,Rounding>::eval(a0, Rounding()); }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      return nt2::crlibm::exp<Rounding>(double(a0));
    }
  };
} }


      
#endif