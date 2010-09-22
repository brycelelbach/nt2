//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_TWO_PROD_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_TWO_PROD_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <boost/fusion/tuple.hpp>

#include <nt2/include/functions/two_split.hpp>

namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<two_prod_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct  result<This(A0,A1)>
          : meta::is_floating_point<A0>{};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute two_prod(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<two_prod_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)>
    {
      typedef typename boost::result_of<meta::floating(A0, A1)>::type rtype;
      typedef typename boost::fusion::tuple<rtype,rtype>              type;
    };

    NT2_FUNCTOR_CALL(2)
    {
      typename NT2_CALL_RETURN_TYPE(2)::type res;
      eval(a0,a1, boost::fusion::at_c<0>(res),boost::fusion::at_c<1>(res));
      return res;
    }

    private:
    template<class A0,class A1,class R0,class R1> inline void
    eval(A0 const& a, A1 const& b,R0& r0, R1& r1)const
    {
      r0  = a*b;
      A0 a1, a2, b1, b2;
      boost::fusion::tie(a1, a2) = two_split(a);
      boost::fusion::tie(b1, b2) = two_split(b);
      r1 = a2*b2 -(((r0-a1*b1)-a2*b1)-a1*b2);
    }
  };
} }


      
#endif