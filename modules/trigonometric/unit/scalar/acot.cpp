//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - acot/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of trigonometric components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 11/02/2011
/// modified by jt the 23/03/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/trigonometric/include/acot.hpp>
// specific includes for arity 1 tests
#include <nt2/toolbox/trigonometric/include/constants.hpp>

NT2_TEST_CASE_TPL ( acot_real__1_0,  NT2_REAL_TYPES)
{
  
  using nt2::acot;
  using nt2::tag::acot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<acot_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(acot(nt2::Half<T>()), 1.107148717794090e+00, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::Inf<T>()), 0, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::Mhalf<T>()), -1.107148717794090e+00, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::Minf<T>()), 0, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::Mone<T>()), -7.853981633974483e-01, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::Nan<T>()), nt2::Nan<r_t>(), 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::One<T>()), 7.853981633974483e-01, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::Zero<T>()), 1.570796326794897e+00, 1.5);
} // end of test for real_

NT2_TEST_CASE_TPL ( acot_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::acot;
  using nt2::tag::acot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<acot_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(acot(nt2::One<T>()), 7.853981633974483e-01, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::Zero<T>()), 1.570796326794897e+00, 1.5);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( acot_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::acot;
  using nt2::tag::acot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<acot_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(acot(nt2::Mone<T>()), -7.853981633974483e-01, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::One<T>()), 7.853981633974483e-01, 1.5);
  NT2_TEST_ULP_EQUAL(acot(nt2::Zero<T>()), 1.570796326794897e+00, 1.5);
} // end of test for signed_int_
