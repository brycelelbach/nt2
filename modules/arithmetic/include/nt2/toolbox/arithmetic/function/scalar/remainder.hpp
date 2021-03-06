//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_REMAINDER_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_REMAINDER_HPP_INCLUDED
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/negate.hpp>
//#include <nt2/include/functions/idivfix.hpp>
#include <nt2/include/functions/idivround.hpp>
#include <nt2/include/functions/divround.hpp>

/////////////////////////////////////////////////////////////////////////////
// The remainder() function computes the remainder of dividing x by y.  The
// return value is x-n*y, where n is the value x / y, rounded to the nearest
// integer.  If the nt2::absolute value of x-n*y is 0.5, n is chosen to be even.
// The drem function is just an alias for the same thing.
/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::remainder_, tag::cpu_,
                           (A0)(A1),
                           (arithmetic_<A0>)(arithmetic_<A1>)
                          )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::remainder_(tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      std::tr1::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
      {
	if (!a1) return a0; 
	return a0-nt2::idivround(a0, a1)*a1; 
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::remainder_, tag::cpu_,
                           (A0)(A1),
                           (real_<A0>)(real_<A1>)
                          )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::remainder_(tag::real_,tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      std::tr1::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      return a0-divround(a0, a1)*a1; 
    }
  };
} }

#endif
// modified by jt the 26/12/2010
