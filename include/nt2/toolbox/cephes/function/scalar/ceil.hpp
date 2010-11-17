//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_CEIL_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_CEIL_HPP_INCLUDED

namespace nt2 { namespace functors
{
  extern "C"{
    extern float cephes_ceilf ( float );
    extern double cephes_ceil ( double );
    extern long double cephes_ceill ( long double );
  }
  /////////////////////////////////////////////////////////////////////////////
  // Compute ceil(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is float
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<cephes::ceil_,tag::scalar_(tag::arithmetic_),float,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_ceilf(a0); }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is double
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<cephes::ceil_,tag::scalar_(tag::arithmetic_),double,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_ceil(a0); }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is long double
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<cephes::ceil_,tag::scalar_(tag::arithmetic_),long double,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_ceill(a0); }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<cephes::ceil_,tag::scalar_(tag::arithmetic_),arithmetic_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type;
      return nt2::cephes::ceil(type(a0));
    }
  };

} }

#endif
/// Revised by jt the 16/11/2010
