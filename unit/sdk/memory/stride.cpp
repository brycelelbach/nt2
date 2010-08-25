/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 0x01.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::memory::stride"

#include <boost/array.hpp>
#include <boost/mpl/vector_c.hpp>
#include <nt2/sdk/memory/stride.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <nt2/sdk/memory/no_padding.hpp>
#include <nt2/sdk/memory/global_padding.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test for stride with no_padding
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(stride_no_padding)
{
  using nt2::stride;
  using boost::array;
  using boost::mpl::vector_c;
  using nt2::memory::no_padding;

  vector_c<int,9,7,5,3> ss4;
  vector_c<int,7,5,3>   ss3;
  vector_c<int,5,3>     ss2;
  vector_c<int,3>       ss1;

  array<int,4> ds4 = {{9,7,5,3}};
  array<int,3> ds3 = {{7,5,3}};
  array<int,2> ds2 = {{5,3}};
  array<int,1> ds1 = {{3}};

  NT2_TEST_EQUAL( (stride<no_padding,1>(ds4)), 9 );
  NT2_TEST_EQUAL( (stride<no_padding,2>(ds4)), 7 );
  NT2_TEST_EQUAL( (stride<no_padding,1>(ds3)), 7 );
  NT2_TEST_EQUAL( (stride<no_padding,3>(ds4)), 5 );
  NT2_TEST_EQUAL( (stride<no_padding,2>(ds3)), 5 );
  NT2_TEST_EQUAL( (stride<no_padding,1>(ds2)), 5 );
  NT2_TEST_EQUAL( (stride<no_padding,4>(ds4)), 3 );
  NT2_TEST_EQUAL( (stride<no_padding,3>(ds3)), 3 );
  NT2_TEST_EQUAL( (stride<no_padding,2>(ds2)), 3 );
  NT2_TEST_EQUAL( (stride<no_padding,1>(ds1)), 3 );

  NT2_TEST_EQUAL( (stride<no_padding,1>(ss4)), 9 );
  NT2_TEST_EQUAL( (stride<no_padding,2>(ss4)), 7 );
  NT2_TEST_EQUAL( (stride<no_padding,1>(ss3)), 7 );
  NT2_TEST_EQUAL( (stride<no_padding,3>(ss4)), 5 );
  NT2_TEST_EQUAL( (stride<no_padding,2>(ss3)), 5 );
  NT2_TEST_EQUAL( (stride<no_padding,1>(ss2)), 5 );
  NT2_TEST_EQUAL( (stride<no_padding,4>(ss4)), 3 );
  NT2_TEST_EQUAL( (stride<no_padding,3>(ss3)), 3 );
  NT2_TEST_EQUAL( (stride<no_padding,2>(ss2)), 3 );
  NT2_TEST_EQUAL( (stride<no_padding,1>(ss1)), 3 );
}

////////////////////////////////////////////////////////////////////////////////
// Test for stride with global_padding
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(stride_global_padding)
{
  using nt2::stride;
  using boost::array;
  using boost::mpl::vector_c;
  using nt2::memory::global_padding;

  vector_c<int,9,7,5,3> ss4;
  vector_c<int,7,5,3>   ss3;
  vector_c<int,5,3>     ss2;
  vector_c<int,3>       ss1;

  array<int,4> ds4 = {{9,7,5,3}};
  array<int,3> ds3 = {{7,5,3}};
  array<int,2> ds2 = {{5,3}};
  array<int,1> ds1 = {{3}};

  NT2_TEST_EQUAL( (stride<global_padding,1>(ds4)), 9 );
  NT2_TEST_EQUAL( (stride<global_padding,2>(ds4)), 7 );
  NT2_TEST_EQUAL( (stride<global_padding,1>(ds3)), 7 );
  NT2_TEST_EQUAL( (stride<global_padding,3>(ds4)), 5 );
  NT2_TEST_EQUAL( (stride<global_padding,2>(ds3)), 5 );
  NT2_TEST_EQUAL( (stride<global_padding,1>(ds2)), 5 );
  NT2_TEST_EQUAL( (stride<global_padding,4>(ds4)), 3 );
  NT2_TEST_EQUAL( (stride<global_padding,3>(ds3)), 3 );
  NT2_TEST_EQUAL( (stride<global_padding,2>(ds2)), 3 );
  NT2_TEST_EQUAL( (stride<global_padding,1>(ds1)), 3 );

  NT2_TEST_EQUAL( (stride<global_padding,1>(ss4)), 9 );
  NT2_TEST_EQUAL( (stride<global_padding,2>(ss4)), 7 );
  NT2_TEST_EQUAL( (stride<global_padding,1>(ss3)), 7 );
  NT2_TEST_EQUAL( (stride<global_padding,3>(ss4)), 5 );
  NT2_TEST_EQUAL( (stride<global_padding,2>(ss3)), 5 );
  NT2_TEST_EQUAL( (stride<global_padding,1>(ss2)), 5 );
  NT2_TEST_EQUAL( (stride<global_padding,4>(ss4)), 3 );
  NT2_TEST_EQUAL( (stride<global_padding,3>(ss3)), 3 );
  NT2_TEST_EQUAL( (stride<global_padding,2>(ss2)), 3 );
  NT2_TEST_EQUAL( (stride<global_padding,1>(ss1)), 3 );
}