##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

################################################################################
# Add global unit driver rules
################################################################################
ADD_CUSTOM_TARGET(euler.scalar.unit)
ADD_CUSTOM_TARGET(euler.simd.unit)
ADD_DEPENDENCIES(euler.unit euler.scalar.unit euler.simd.unit)

##############################################################################
# Toolbox euler unit tests
##############################################################################
nt2_module_use_modules(unit cephes)
ADD_SUBDIRECTORY(scalar)
ADD_SUBDIRECTORY(simd)
