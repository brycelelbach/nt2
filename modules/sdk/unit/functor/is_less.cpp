/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::is_less"

#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/functor/operators.hpp>
#include <boost/type_traits/is_same.hpp>

#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test behavior for complement
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( is_less, NT2_TYPES )
{
  using boost::is_same;
  using nt2::tag::is_less_;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<is_less_(T,T)>::type
                            , bool
                            >::value
            )
          );

  NT2_TEST_EQUAL( nt2::is_less(T(0),T(0)) , false );
  NT2_TEST_EQUAL( nt2::is_less(T(0),T(1)) , true  );
  NT2_TEST_EQUAL( nt2::is_less(T(1),T(0)) , false );

  NT2_TEST_EQUAL( nt2::lt(T(0),T(0)) , false );
  NT2_TEST_EQUAL( nt2::lt(T(0),T(1)) , true  );
  NT2_TEST_EQUAL( nt2::lt(T(1),T(0)) , false );
}

