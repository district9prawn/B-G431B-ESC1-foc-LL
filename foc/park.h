/*********************************************************************
* File    : park.h
* Title   : Park Transform library
**********************************************************************
*/

#ifndef PARK_H
#define PARK_H


/* Includes */
#include "math.h"
#include "utils.h"

/*  Run Park transform */
__STATIC_INLINE void park_run(volatile float *ab, float sinval, float cosval,
                               volatile float *dq)
{
  dq[0] = (ab[0] * cosval) + (ab[1] * sinval);
  dq[1] = -(ab[0] * sinval) + (ab[1] * cosval);
}

/* Run inverse Park transform */
__STATIC_INLINE void ipark_run(volatile float *dq, float sinval, float cosval,
                                volatile float *ab)
{
  ab[0] = (dq[0] * cosval) - (dq[1] * sinval);
  ab[1] = (dq[0] * sinval) + (dq[1] * cosval);
}                                 

#endif // end of CLARKE_h defines
       

