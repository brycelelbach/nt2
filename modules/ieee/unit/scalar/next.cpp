//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 ieee toolbox - next/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of ieee components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 04/12/2010
/// modified by jt the 22/03/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/ieee/include/next.hpp>
// specific includes for arity 1 tests
#include <nt2/include/functions/successor.hpp>
#include <nt2/sdk/constant/eps_related.hpp>

NT2_TEST_CASE_TPL ( next_real__1_0,  NT2_REAL_TYPES)
{
  
  using nt2::next;
  using nt2::tag::next_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<next_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(next(nt2::Inf<T>()), nt2::Inf<r_t>());
  NT2_TEST_EQUAL(next(nt2::Minf<T>()), nt2::Valmin<r_t>());
  NT2_TEST_EQUAL(next(nt2::Mone<T>()), nt2::Mone<r_t>()+nt2::Eps<r_t>()/2);
  NT2_TEST_EQUAL(next(nt2::Nan<T>()), nt2::Nan<r_t>());
  NT2_TEST_EQUAL(next(nt2::One<T>()), nt2::One<r_t>()+nt2::Eps<r_t>());
  NT2_TEST_EQUAL(next(nt2::Valmax<T>()), nt2::Inf<r_t>());
  NT2_TEST_EQUAL(next(nt2::Zero<T>()), nt2::Zero<r_t>()+nt2::Mindenormal<T>());
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-10), T(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for (uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_EQUAL( nt2::next(a0),nt2::successor(a0));
     }
     
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( next_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::next;
  using nt2::tag::next_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<next_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(next(nt2::One<T>()), nt2::Two<r_t>());
  NT2_TEST_EQUAL(next(nt2::Valmax<T>()), nt2::Valmax<r_t>());
  NT2_TEST_EQUAL(next(nt2::Zero<T>()), nt2::One<r_t>());
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, 0, 100);
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for (uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_EQUAL( nt2::next(a0),nt2::successor(a0));
     }
     
   }
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( next_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::next;
  using nt2::tag::next_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<next_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(next(nt2::Mone<T>()), nt2::Zero<r_t>());
  NT2_TEST_EQUAL(next(nt2::One<T>()), nt2::Two<r_t>());
  NT2_TEST_EQUAL(next(nt2::Valmax<T>()), nt2::Valmax<r_t>());
  NT2_TEST_EQUAL(next(nt2::Zero<T>()), nt2::One<r_t>());
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, -100, 100);
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for (uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_EQUAL( nt2::next(a0),nt2::successor(a0));
     }
     
   }
} // end of test for signed_int_
