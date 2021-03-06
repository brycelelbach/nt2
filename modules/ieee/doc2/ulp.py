[{'functor': {'arity': '1',
              'call_types': [],
              'ret_arity': '0',
              'rturn': {'default': 'typename boost::result_of<nt2::meta::arithmetic(T)>::type'},
              'type_defs': [],
              'types': ['real_', 'unsigned_int_', 'signed_int_']},
  'unit': {'global_header': {'first_stamp': 'modified by jt the 04/12/2010',
                             'included': ['#include <nt2/include/functions/min.hpp>',
                                          '#include <nt2/include/functions/next.hpp>',
                                          '#include <nt2/include/functions/prev.hpp>'],
                             'notes': [],
                             'ranges': {'real_': [['T(-10)', 'T(10)']],
                                        'signed_int_': [['-100', '100']],
                                        'unsigned_int_': [['0', '100']]},
                             'specific_values': {'default': {},
                                                 'real_': {'nt2::Inf<T>()': 'nt2::Inf<r_t>()',
                                                           'nt2::Minf<T>()': 'nt2::Inf<r_t>()',
                                                           'nt2::Mone<T>()': 'nt2::Eps<r_t>()/2',
                                                           'nt2::Nan<T>()': 'nt2::Nan<r_t>()',
                                                           'nt2::One<T>()': 'nt2::Eps<r_t>()/2',
                                                           'nt2::Zero<T>()': 'nt2::Smallestposval<r_t>()'},
                                                 'signed_int_': {'nt2::Mone<T>()': 'nt2::One<r_t>()',
                                                                 'nt2::One<T>()': 'nt2::One<r_t>()',
                                                                 'nt2::Zero<T>()': 'nt2::One<r_t>()'},
                                                 'unsigned_int_': {'nt2::One<T>()': 'nt2::One<r_t>()',
                                                                   'nt2::Zero<T>()': 'nt2::One<r_t>()'}},
                             'stamp': 'modified by jt the 12/12/2010',
                             'verif_test': {'property_call': None,
                                            'property_value': {'default': [{'default': 'nt2::One<T>()',
                                                                            'real_': 'nt2::min(a0-nt2::prev(a0),nt2::next(a0)-a0)'}]},
                                            'ulp_thresh': '0'}}},
  'version': '0.1'}]