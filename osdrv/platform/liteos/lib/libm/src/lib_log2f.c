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
#include "k_logf.h"

static const float
two25      =  3.3554432000e+07, /* 0x4c000000 */
ivln2hi    =  1.4428710938e+00, /* 0x3fb8b000 */
ivln2lo    = -1.7605285393e-04; /* 0xb9389ad4 */

static const float zero   =  0.0;
static volatile float vzero = 0.0;

float
__ieee754_log2f(float x)
{
    float f,hfsq,hi,lo,r,y;
    int i,k,hx;

    GET_FLOAT_WORD(hx,x);

    k=0;
    if (hx < 0x00800000) {            /* x < 2**-126  */
        if ((hx&0x7fffffff)==0)
        return -two25/vzero;        /* log(+-0)=-inf */
        if (hx<0) return (x-x)/zero;    /* log(-#) = NaN */ /*lint !e414*/
        k -= 25; x *= two25; /* subnormal number, scale up x */
        GET_FLOAT_WORD(hx,x);
    }
    if (hx >= 0x7f800000) return x+x;
    if (hx == 0x3f800000)
        return zero;            /* log(1) = +0 */
    k += (hx>>23)-127;
    hx &= 0x007fffff;
    i = (hx+(0x4afb0d))&0x800000;
    SET_FLOAT_WORD(x,hx|(i^0x3f800000));    /* normalize x or x/2 */
    k += (i>>23);
    y = (float)k;
    f = x - (float)1.0;
    hfsq = (float)0.5*f*f;
    r = k_log1pf(f);

    hi = f - hfsq;
    GET_FLOAT_WORD(hx,hi);
    SET_FLOAT_WORD(hi,hx&0xfffff000);
    lo = (f - hi) - hfsq + r;
    return (lo+hi)*ivln2lo + lo*ivln2hi + hi*ivln2hi + y;
}

float log2f(float x)
{
    return __ieee754_log2f(x);
}