/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_FUNCTOR_DETAILS_ARITHMETIC_HPP_INCLUDED
#define NT2_SDK_FUNCTOR_DETAILS_ARITHMETIC_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// boolean operators implementation
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/functor/preprocessor/call.hpp>

#define NT2_LOCAL_TYPE(Z,N,T)                 \
static typename boost::add_reference<BOOST_PP_CAT(A,N)>::type  BOOST_PP_CAT(a,N); \
/**/

#define NT2_MAKE_ARITHMETIC(TAG,N,IMPL)                             \
template<class Category,class Info> struct call<TAG,Category,Info>  \
{                                                                   \
  template<class Sig> struct result;                                \
  template<class This,BOOST_PP_ENUM_PARAMS(N,class A)>              \
  struct result<This(BOOST_PP_ENUM_PARAMS(N,A))>                    \
  {                                                                 \
    BOOST_PP_REPEAT(N,NT2_LOCAL_TYPE,~)                             \
    BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested,IMPL)                    \
    typedef typename nested::type type;                             \
  };                                                                \
  NT2_FUNCTOR_CALL(N) { return IMPL; }                              \
}                                                                   \
/**/

namespace nt2 { namespace functors
{
  //////////////////////////////////////////////////////////////////////////////
  // Generating implemetnation from the macro
  //////////////////////////////////////////////////////////////////////////////
  NT2_MAKE_ARITHMETIC(complement_      , 1 , (~a0)     );
  NT2_MAKE_ARITHMETIC(neg_             , 1 , (-a0)     );
  NT2_MAKE_ARITHMETIC(unary_plus_      , 1 , (+a0)     );
  NT2_MAKE_ARITHMETIC(plus_            , 2 , (a0 +  a1));
  NT2_MAKE_ARITHMETIC(minus_           , 2 , (a0 -  a1));
  NT2_MAKE_ARITHMETIC(multiplies_      , 2 , (a0 *  a1));
  NT2_MAKE_ARITHMETIC(divides_         , 2 , (a0 /  a1));
  NT2_MAKE_ARITHMETIC(modulo_          , 2 , (a0 %  a1));
  NT2_MAKE_ARITHMETIC(bitwise_and_     , 2 , (a0 &  a1));
  NT2_MAKE_ARITHMETIC(bitwise_or_      , 2 , (a0 |  a1));
  NT2_MAKE_ARITHMETIC(bitwise_xor_     , 2 , (a0 ^  a1));
  NT2_MAKE_ARITHMETIC(shift_left_      , 2 , (a0 << a1));
  NT2_MAKE_ARITHMETIC(shift_right_     , 2 , (a0 >> a1));
} }

#undef NT2_MAKE_ARITHMETIC

#endif