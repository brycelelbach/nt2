/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_META_FROM_BITS_HPP_INCLUDED
#define NT2_SDK_META_FROM_BITS_HPP_INCLUDED

#include <nt2/sdk/meta/category.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/category_of.hpp>

namespace nt2 { namespace details
{
  template<class T, class Sign, class Categry>	struct from_bits;

  template<class T, class Sign, class X>
  struct from_bits<T, Sign, tag::scalar_(X)>
	{
		typedef union
		{
			typename meta::as_integer<T, Sign>::type  bits;
			T  																				value;
		} type;
	};
} }

namespace nt2 { namespace meta
{
  //////////////////////////////////////////////////////////////////////////////
  // Take a bit pattern and turn it into a value
  //////////////////////////////////////////////////////////////////////////////
  template<class T, class Sign = unsigned>
  struct  from_bits
        : details::from_bits<T,Sign,typename category_of<T>::type::tag > {};
} }

#endif
