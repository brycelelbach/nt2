//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - correct_fma/scalar Mode"

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
#include <nt2/toolbox/arithmetic/include/correct_fma.hpp>
// specific includes for arity 3 tests
#include <nt2/sdk/constant/eps_related.hpp>

NT2_TEST_CASE_TPL ( correct_fma_real__3,  NT2_REAL_TYPES)
{
  using nt2::correct_fma;
  using nt2::functors::correct_fma_;
  typedef typename nt2::meta::call<correct_fma_(T,T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T,T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::Inf<T>(), nt2::Inf<T>(), nt2::Inf<T>()), nt2::Inf<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::Minf<T>(), nt2::Minf<T>(), nt2::Minf<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::Mone<T>(), nt2::Mone<T>(), nt2::Mone<T>()), nt2::Zero<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::Nan<T>(), nt2::Nan<T>(), nt2::Nan<T>()), nt2::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::One<T>(), nt2::One<T>(), nt2::One<T>()), nt2::Two<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::One<T>()+nt2::Eps<T>(), nt2::One<T>()-nt2::Eps<T>(),nt2::Mone<T>()), -nt2::Eps<T>()*nt2::Eps<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::Zero<T>(), nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);
  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, T(-10), T(10));
    NT2_CREATE_BUFFER(a1,T, 100, T(-10), T(10));
    NT2_CREATE_BUFFER(a2,T, 100, T(-10), T(10));
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << ", a2 = "<< u_t(a2 = tab_a2[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::correct_fma(a0,a1,a2),a0*a1+a2,0);
     }
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( correct_fma_signed_int__3,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::correct_fma;
  using nt2::functors::correct_fma_;
  typedef typename nt2::meta::call<correct_fma_(T,T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T,T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::Mone<T>(), nt2::Mone<T>(), nt2::Mone<T>()), nt2::Zero<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::One<T>(), nt2::One<T>(), nt2::One<T>()), nt2::Two<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::Zero<T>(), nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);
  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, nt2::Valmin<T>(), nt2::Valmax<T>());
    NT2_CREATE_BUFFER(a1,T, 100, nt2::Valmin<T>(), nt2::Valmax<T>());
    NT2_CREATE_BUFFER(a2,T, 100, nt2::Valmin<T>(), nt2::Valmax<T>());
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << ", a2 = "<< u_t(a2 = tab_a2[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::correct_fma(a0,a1,a2),a0*a1+a2,0);
     }
   }
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( correct_fma_unsigned_int__3,  NT2_UNSIGNED_TYPES)
{
  using nt2::correct_fma;
  using nt2::functors::correct_fma_;
  typedef typename nt2::meta::call<correct_fma_(T,T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::arithmetic(T,T,T)>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::One<T>(), nt2::One<T>(), nt2::One<T>()), nt2::Two<T>(), 0);
  NT2_TEST_ULP_EQUAL(  correct_fma(nt2::Zero<T>(), nt2::Zero<T>(), nt2::Zero<T>()), nt2::Zero<T>(), 0);
  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, nt2::Valmin<T>(), nt2::Valmax<T>());
    NT2_CREATE_BUFFER(a1,T, 100, nt2::Valmin<T>(), nt2::Valmax<T>());
    NT2_CREATE_BUFFER(a2,T, 100, nt2::Valmin<T>(), nt2::Valmax<T>());
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << ", a2 = "<< u_t(a2 = tab_a2[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::correct_fma(a0,a1,a2),a0*a1+a2,0);
     }
   }
} // end of test for unsigned_int_