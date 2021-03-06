#define NT2_UNIT_MODULE "nt2 $self.tb_name$ toolbox - $self.name$ - $acts$ Mode"

#include <nt2/toolbox/$self.tb_name$/include/$self.name$.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/simd/native.hpp>
#include <../unit/sdk/simd/types.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <boost/type_traits/is_same.hpp>

//////////////////////////////////////////////////////////////////////////////
// Test behavior of $self.tb_name$ component $self.name$ using NT2_TEST_CASE
//////////////////////////////////////////////////////////////////////////////
//NT2_TEST_CASE_TPL($self.name$, NT2_SIMD_TYPES )
//{
//  using nt2::$self.name$;
//  using nt2::functors::$self.name$;
// 
//  using nt2::simd::native;
//  using nt2::meta::cardinal_of;
//
//  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
//  typedef native<T,ext_t>             n_t;
//
//  NT2_TEST( (boost::is_same<typename nt2::meta::call<$self.tb_name$_($self.const_type_n_t_list$)>::type,
//                            typename std::tr1::result_of<nt2::meta::floating<($self.const_n_t_type_list$)>::type
//                            >::value)
//          );
//  NT2_ALIGNED_TYPE(T) data[$self.arity$*cardinal_of<n_t>::value];
//  for(std::size_t i=0;i<$self.arity$*cardinal_of<n_t>::value;++i)
//    data[i] = i; // good value here for $self.name$
//
$self.gl_list$
//    n_t v  = $self.name$($self.parm_list$);
//    for(std::size_t j=0;j<cardinal_of<n_t>::value;++j)
//    {
//      NT2_TEST_EQUAL( v[j], $self.name$($self.parm_list_j$) );
//    }
//  }
//}

