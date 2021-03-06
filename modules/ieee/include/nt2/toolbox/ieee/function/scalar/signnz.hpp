//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_SIGNNZ_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_SIGNNZ_HPP_INCLUDED
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>

#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/is_gez.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/include/functions/is_positive.hpp>
#include <nt2/include/functions/is_negative.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is signed_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::signnz_, tag::cpu_,
                        (A0),
                        (signed_<A0>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::signnz_(tag::signed_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      std::tr1::result_of<meta::arithmetic(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      return is_gez(a0)-is_ltz(a0);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::signnz_, tag::cpu_,
                        (A0),
                        (unsigned_<A0>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::signnz_(tag::unsigned_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      std::tr1::result_of<meta::arithmetic(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      details::ignore_unused(a0);
      return One<A0>();
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::signnz_, tag::cpu_,
                        (A0),
                        (real_<A0>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::signnz_(tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      std::tr1::result_of<meta::arithmetic(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      return is_nan(a0)?a0:is_positive(a0)-is_negative(a0);
    }
  };
} }

#endif
// modified by jt the 26/12/2010