[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '4',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : [],
         'special' : ['gsl_specfun'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 10/03/2011',
             'included' : [],
             'no_ulp' : 'False',
             'notes' : [],
             'stamp' : 'modified by jt the 10/03/2011',
            },
         'ranges' : {
             'default' : [['T(0)', 'T(10)'], ['T(0)', 'T(10)'], ['T(0)', 'T(10)'], ['T(-1)', 'T(1)']],
            },
         'specific_values' : {
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::gsl_specfun::gsl_sf_hyperg_2f1(a0,a1,a2,a3)'],
                },
             'property_value' : {
                 'default' : ['nt2::gsl_specfun::gsl_sf_hyperg_2f1(a0,a1,a2,a3)'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'default' : ['1'],
                },
            },
        },
    },
]
