{ 'arity': 1, 
  'dptch': ['real_', 'arithmetic_'],
  'incld': ["#include<nt2/toolbox/standard/include/ceil.hpp>"],
  'norst': False,
  'rnges': { 'default': [['nt2::Valmin<T>()', 'nt2::Valmax<T>()']],
             'real_'   : [['T(-100)','T(100)']],
             'signed_int_' :[['T(-100)','T(100)']],
             'unsigned_int_' :[['T(0)','T(100)']],
             },
  'rturn': { 'default': 'T'},
  'specv': { 'default': { },
             'real_': { 'nt2::Inf<T>()' : 'nt2::Inf<T>()',
                        'nt2::Minf<T>()': 'nt2::Minf<T>()',
                        'nt2::Mone<T>()': 'nt2::Mone<T>()',
                        'nt2::Nan<T>()' : 'nt2::Nan<T>()',
                        'nt2::One<T>()' : 'nt2::One<T>()',
                        'nt2::Zero<T>()': 'nt2::Zero<T>()',
                        'T(1.1)'        : 'r_t(2)',
                        'T(-1.1)'       : 'r_t(-1)'
                        },
             'signed_int_': { 'nt2::Mone<T>()': 'nt2::Mone<T>()',
                              'nt2::One<T>()': 'nt2::One<T>()',
                              'nt2::Zero<T>()': 'nt2::Zero<T>()'},
             'unsigned_int_': { 'nt2::One<T>()': 'nt2::One<T>()',
                                'nt2::Zero<T>()': 'nt2::Zero<T>()'}},
  'stamp': 'modified by jt the 28/11/2010',
  'tcall':"nt2::standard::ceil(a0)",
  'types': ['real_', 'signed_int_','unsigned_int_'],
  'versn': 0.0}
