/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_NT2_SDK_ERRORS_DETAILS_MESSAGE_HPP_INCLUDED
#define NT2_NT2_SDK_ERRORS_DETAILS_MESSAGE_HPP_INCLUDED

#include <nt2/sdk/sys/string.hpp>

namespace nt2 { namespace details
{
  //////////////////////////////////////////////////////////////////////////////
  // Build a warning string from warning/assertion info
  //////////////////////////////////////////////////////////////////////////////
  sys::string
  message ( const char* header, const char* msg
          , const char* fn, const char* file
          , int line
          );
} }

#endif