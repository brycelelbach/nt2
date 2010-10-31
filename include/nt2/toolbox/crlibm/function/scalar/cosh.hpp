//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_COSH_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_COSH_HPP_INCLUDED

namespace nt2 { namespace functors
{
  extern "C"{
    extern double cosh_rn ( double );
    extern double cosh_rd ( double );
    extern double cosh_rz ( double );
    extern double cosh_ru ( double );
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute cosh(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Rounding, class Info>
  struct call<crlibm::cosh_<Rounding>,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH( 1, A0, (2, (double,arithmetic_)) )
    template<class A0, class R> struct inner_cosh;
    NT2_CRLIBM_INNER_STRUCT(rn, cosh, rn)
    NT2_CRLIBM_INNER_STRUCT(rd, cosh, rd)
    NT2_CRLIBM_INNER_STRUCT(ru, cosh, ru)
    NT2_CRLIBM_INNER_STRUCT(rz, cosh, rz)
    NT2_FUNCTOR_CALL_EVAL_IF(1, double)
      {return inner_cosh<A0,Rounding>::eval(a0, Rounding()); }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      return nt2::crlibm::cosh<Rounding>(double(a0));
    }
  };
} }


      
#endif