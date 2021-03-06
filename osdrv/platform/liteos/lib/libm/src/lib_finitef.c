/* s_finitef.c -- float version of s_finite.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */


#include "math.h"
#include "float.h"

int finitef(float x)
{
    int ix;
    GET_FLOAT_WORD(ix,x);
    return (int)((unsigned int)((ix&0x7fffffff)-0x7f800000)>>31);
}

