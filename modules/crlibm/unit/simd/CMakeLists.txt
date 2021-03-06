##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
  exp_rn.cpp
  acos_rz.cpp
  exp.cpp
  exp_rd.cpp
  exp_rz.cpp
  exp_ru.cpp
  acos_ru.cpp
  log1p_rz.cpp
  atan.cpp
  sin.cpp
  asinpi.cpp
  tan.cpp
  tanpi_ru.cpp
  tanpi_rz.cpp
  tanpi_rd.cpp
  tanpi_rn.cpp
  log2_ru.cpp
  log1p.cpp
  sinh_rd.cpp
  sinh_rn.cpp
  log2_rz.cpp
  log2_rd.cpp
  sinh_ru.cpp
  sinh_rz.cpp
  sinpi_rz.cpp
  log2_rn.cpp
  tanpi.cpp
  asin_rn.cpp
  tan_ru.cpp
  tan_rz.cpp
  cos.cpp
  tan_rd.cpp
  tan_rn.cpp
  log10.cpp
  cos_rn.cpp
  cos_rd.cpp
  cos_rz.cpp
  log.cpp
  cos_ru.cpp
  atan_ru.cpp
  sinh.cpp
  atanpi_rn.cpp
  acos.cpp
  sinpi_rd.cpp
  log1p_ru.cpp
  atanpi_rd.cpp
  sinpi_rn.cpp
  acospi.cpp
  log1p_rn.cpp
  atanpi_rz.cpp
  sinpi_ru.cpp
  log1p_rd.cpp
  atanpi_ru.cpp
  expm1.cpp
  atan_rz.cpp
  asinpi_rd.cpp
  expm1_ru.cpp
  asinpi_rn.cpp
  atanpi.cpp
  asinpi_ru.cpp
  atan_rd.cpp
  log2.cpp
  asinpi_rz.cpp
  acos_rn.cpp
  log_rd.cpp
  cosh_rd.cpp
  log10_rz.cpp
  log10_ru.cpp
  acos_rd.cpp
  sinpi.cpp
  cosh_rn.cpp
  log10_rn.cpp
  cosh_ru.cpp
  log10_rd.cpp
  cosh_rz.cpp
  log_rz.cpp
  asin.cpp
  asin_rz.cpp
  asin_ru.cpp
  cosh.cpp
  expm1_rn.cpp
  atan_rn.cpp
  asin_rd.cpp
  sin_rn.cpp
  pow_rn.cpp
  sin_rd.cpp
  expm1_rd.cpp
  sin_rz.cpp
  sin_ru.cpp
  cospi_rn.cpp
  cospi_rd.cpp
  cospi_rz.cpp
  log_rn.cpp
  cospi_ru.cpp
  acospi_rd.cpp
  acospi_rn.cpp
  acospi_ru.cpp
  acospi_rz.cpp
  cospi.cpp
  expm1_rz.cpp
  log_ru.cpp
# List of simd test files for toolbox crlibm
   )

##****************************************************************************
# For each filename
##****************************************************************************
FOREACH( EXAMPLE ${SOURCES})
  STRING(REGEX REPLACE ".cpp" "" EXAMPLE ${EXAMPLE})
  nt2_module_add_unit(crlibm.simd.${EXAMPLE}.unit ${EXAMPLE}.cpp)
ENDFOREACH()
