{ 'arity': 3,
  'dptch': ['fundamental_'],
  'incld': ["#include <nt2/sdk/constant/eps_related.hpp>"],
  'notes': [''],
  'rnges': { 'default': [ ['nt2::Valmin<T>()', 'nt2::Valmax<T>()'],
                          ['nt2::Valmin<T>()', 'nt2::Valmax<T>()'],
                          ['nt2::Valmin<T>()', 'nt2::Valmax<T>()']],
             'real_': [ ['T(-10)', 'T(10)'],
                        ['T(-10)', 'T(10)'],
                        ['T(-10)', 'T(10)']]},
  'rturn': { 'default': 'typename boost::result_of<nt2::meta::arithmetic(T,T,T)>::type'}, 
  'specv': { 'default': { },
             'real_': { 'nt2::Inf<T>()': 'nt2::Inf<T>()',
                        'nt2::Minf<T>()': 'nt2::Nan<T>()',
                        'nt2::Mone<T>()': 'nt2::Zero<T>()',
                        'nt2::Nan<T>()': 'nt2::Nan<T>()',
                        'nt2::One<T>()': 'nt2::Two<T>()',
                        'nt2::Zero<T>()': 'nt2::Zero<T>()',
                        'nt2::One<T>()+nt2::Eps<T>(), nt2::One<T>()-nt2::Eps<T>(),nt2::Mone<T>()':'-nt2::Eps<T>()*nt2::Eps<T>()',
                        },
             'signed_int_': { 'nt2::Mone<T>()': 'nt2::Zero<T>()',
                              'nt2::One<T>()': 'nt2::Two<T>()',
                              'nt2::Zero<T>()': 'nt2::Zero<T>()'},
             'unsigned_int_': { 'nt2::One<T>()': 'nt2::Two<T>()',
                                'nt2::Zero<T>()': 'nt2::Zero<T>()'}},
  'tcall': 'a0*a1+a2',
  'types': ['real_', 'signed_int_', 'unsigned_int_'],
  'stamp': 'modified by jt the 28/11/2010',
  'versn': 0.0}
