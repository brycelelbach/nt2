/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_FUNCTOR_META_CATEGORIZE_HPP_INCLUDED
#define NT2_SDK_FUNCTOR_META_CATEGORIZE_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Defines how a functor categorize its arguments
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/functor/meta/dominant.hpp>

#if !defined(BOOST_HAS_VARIADIC_TMPL)
#include <nt2/extension/parameters.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#endif

namespace nt2 { namespace meta
{
  #if defined(BOOST_HAS_VARIADIC_TMPL)
  template<class Tag, class Info, class... Args>
  struct  categorize
  {
    typedef typename dominant<Args...>::type::tag type;
  };
  #else
  template< class Tag, class Info
          , BOOST_PP_ENUM_BINARY_PARAMS ( NT2_MAX_ARITY
                                        , class A
                                        , = meta::na_ BOOST_PP_INTERCEPT
                                        )
          >
  struct categorize
  {
    typedef typename
    dominant<BOOST_PP_ENUM_PARAMS(NT2_MAX_ARITY,A)>::type::tag type;
  };
  #endif
} }

#endif