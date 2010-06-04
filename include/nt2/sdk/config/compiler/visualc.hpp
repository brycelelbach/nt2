/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONFIG_COMPILER_VISUALC_HPP_INCLUDED
#define NT2_SDK_CONFIG_COMPILER_VISUALC_HPP_INCLUDED

#if !defined(NT2_COMPILER_DETECTED)
  #if defined(BOOST_MSVC) || defined(DOXYGEN_ONLY)

    // Check for compliance to:
    // http://www.boost.org/development/requirements.html#Design_and_Programming
    //#undef min
    //#undef max

    #pragma warning( disable : 4554 ) // precedence on & operator
    #pragma warning( disable : 4244 ) // converting types to double
    #pragma warning( disable : 4804 ) // unsafe use of >
    #pragma warning( disable : 4996 ) // unsafe iostream call

    #ifdef NT2_VERBOSE
    #warning NT2 Configuration: MSVC compiler detected.
    #endif

    #define NT2_COMPILER_DETECTED
    #define NT2_COMPILER_MSVC
    #define NT2_COMPILER_STRING   BOOST_COMPILER

  #endif
#endif
#endif