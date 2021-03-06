//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 bitwise toolbox - select/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of bitwise components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
/// modified by jt the 16/03/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/bitwise/include/select.hpp>

NT2_TEST_CASE_TPL ( select_real__3,  NT2_REAL_TYPES)
{
  using nt2::select;
  using nt2::tag::select_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<select_(vT,vT,vT)>::type r_t;
  typedef typename nt2::meta::call<select_(T,T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;

  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0), T(0));
    NT2_CREATE_BUF(tab_a1,T, NR, T(-10000), T(10000));
    NT2_CREATE_BUF(tab_a2,T, NR, T(-10000), T(10000));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        vT a1 = load<vT>(&tab_a1[0],j);
        vT a2 = load<vT>(&tab_a2[0],j);
        r_t v = select(a0,a1,a2);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          NT2_TEST_EQUAL( v[i],ssr_t(nt2::select(tab_a0[k],tab_a1[k],tab_a2[k])));
        }
      }
    
  }
  {
    NT2_CREATE_BUF(tab_a0,T, NR, nt2::Nan<T>(), nt2::Nan<T>());
    NT2_CREATE_BUF(tab_a1,T, NR, T(-10000), T(10000));
    NT2_CREATE_BUF(tab_a2,T, NR, T(-10000), T(10000));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        vT a1 = load<vT>(&tab_a1[0],j);
        vT a2 = load<vT>(&tab_a2[0],j);
        r_t v = select(a0,a1,a2);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          NT2_TEST_EQUAL( v[i],ssr_t(nt2::select(tab_a0[k],tab_a1[k],tab_a2[k])));
        }
      }
    
  }
} // end of test for real_

NT2_TEST_CASE_TPL ( select_integer__3,  NT2_INTEGRAL_TYPES)
{
  using nt2::select;
  using nt2::tag::select_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<select_(vT,vT,vT)>::type r_t;
  typedef typename nt2::meta::call<select_(T,T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;

  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0), T(0));
    NT2_CREATE_BUF(tab_a1,T, NR, T(-10000), T(10000));
    NT2_CREATE_BUF(tab_a2,T, NR, T(-10000), T(10000));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        vT a1 = load<vT>(&tab_a1[0],j);
        vT a2 = load<vT>(&tab_a2[0],j);
        r_t v = select(a0,a1,a2);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          NT2_TEST_EQUAL( v[i],ssr_t(nt2::select(tab_a0[k],tab_a1[k],tab_a2[k])));
        }
      }
    
  }
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-1), T(-1));
    NT2_CREATE_BUF(tab_a1,T, NR, T(-10000), T(10000));
    NT2_CREATE_BUF(tab_a2,T, NR, T(-10000), T(10000));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        vT a1 = load<vT>(&tab_a1[0],j);
        vT a2 = load<vT>(&tab_a2[0],j);
        r_t v = select(a0,a1,a2);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          NT2_TEST_EQUAL( v[i],ssr_t(nt2::select(tab_a0[k],tab_a1[k],tab_a2[k])));
        }
      }
    
  }
} // end of test for integer_
