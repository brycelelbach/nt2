
/* @(#)w_j0.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

/*
 * wrapper j0(double x), y0(double x)
 */

#include "fdlibm.h"

#ifdef __STDC__
	double fd_j0(double x)		/* wrapper j0 */
#else
	double fd_j0(x)			/* wrapper j0 */
	double x;
#endif
{
#ifdef _IEEE_LIBM
	return fd___ieee754_j0(x);
#else
	double z = fd___ieee754_j0(x);
	if(_LIB_VERSION == _IEEE_ || fd_isnan(x)) return z;
	if(fd_fabs(x)>X_TLOSS) {
	        return fd___kernel_standard(x,x,34); /* j0(|x|>X_TLOSS) */
	} else
	    return z;
#endif
}

#ifdef __STDC__
	double fd_y0(double x)		/* wrapper y0 */
#else
	double fd_y0(x)			/* wrapper y0 */
	double x;
#endif
{
#ifdef _IEEE_LIBM
	return fd___ieee754_y0(x);
#else
	double z;
	z = fd___ieee754_y0(x);
	if(_LIB_VERSION == _IEEE_ || fd_isnan(x) ) return z;
        if(x <= 0.0){
                if(x==0.0)
                    /* d= -one/(x-x); */
                    return fd___kernel_standard(x,x,8);
                else
                    /* d = zero/(x-x); */
                    return fd___kernel_standard(x,x,9);
        }
	if(x>X_TLOSS) {
	        return fd___kernel_standard(x,x,35); /* y0(x>X_TLOSS) */
	} else
	    return z;
#endif
}