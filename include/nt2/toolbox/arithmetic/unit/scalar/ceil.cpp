//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - ceil/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/arithmetic/include/ceil.hpp>
// specific includes for arity 1 tests
#include<nt2/toolbox/standard/include/ceil.hpp>

NT2_TEST_CASE_TPL ( ceil_real__1,  NT2_REAL_TYPES)
{
  using nt2::ceil;
  using nt2::functors::ceil_;
  typedef typename nt2::meta::call<ceil_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  ceil(T(-1.1)), r_t(-1), 0);
  NT2_TEST_ULP_EQUAL(  ceil(T(1.1)), r_t(2), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::Inf<T>()), nt2::Inf<T>(), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::Minf<T>()), nt2::Minf<T>(), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::Mone<T>()), nt2::Mone<T>(), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::Nan<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::Zero<T>()), nt2::Zero<T>(), 0);
  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, T(-100), T(100));
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::ceil(a0),nt2::standard::ceil(a0),0);
     }
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( ceil_signed_int__1,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::ceil;
  using nt2::functors::ceil_;
  typedef typename nt2::meta::call<ceil_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  ceil(nt2::Mone<T>()), nt2::Mone<T>(), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::Zero<T>()), nt2::Zero<T>(), 0);
  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, T(-100), T(100));
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::ceil(a0),nt2::standard::ceil(a0),0);
     }
   }
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( ceil_unsigned_int__1,  NT2_UNSIGNED_TYPES)
{
  using nt2::ceil;
  using nt2::functors::ceil_;
  typedef typename nt2::meta::call<ceil_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  ceil(nt2::One<T>()), nt2::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(  ceil(nt2::Zero<T>()), nt2::Zero<T>(), 0);
  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, T(0), T(100));
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::ceil(a0),nt2::standard::ceil(a0),0);
     }
   }
} // end of test for unsigned_int_