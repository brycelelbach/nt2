##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

##############################################################################
###     Toolbox exponential bench tests
##############################################################################

ADD_CUSTOM_TARGET(exponential.scalar.bench)
ADD_CUSTOM_TARGET(exponential.simd.bench)
ADD_DEPENDENCIES(exponential.bench exponential.scalar.bench exponential.simd.bench)

ADD_SUBDIRECTORY(scalar)
ADD_SUBDIRECTORY(simd)
