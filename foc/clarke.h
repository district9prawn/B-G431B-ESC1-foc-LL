/*********************************************************************
* File    : clarke.h
* Title   : Clarke Transform library
**********************************************************************
*/

#ifndef CLARKE_H
#define CLARKE_H


/* Includes */
#include "math.h"
#include "utils.h"

/* Perform Clarke transform using full formula */
__STATIC_INLINE void clarke_full_run(volatile float *abc, volatile float *ab)
{
  ab[0] = alpha_sf * (2.0f * abc[0]) - alpha_sf * (abc[1] + abc[2]);
  ab[1] = beta_sf * (abc[1] - abc[2]);
}

  /* Simplified Clarke transform using two values. */ 
  //*alpha = abc_a;
  //*beta = M_ONE_ON_SQRT3 * abc_a + M_TWO_ON_SQRT3 * abc_b;

/* Run inverse Clarke transform */
__STATIC_INLINE void iclarke_run(volatile float *ab, volatile float *abc)
{
  abc[0] = ab[0];
  abc[1] = -(0.5f * ab[0]) + (M_SQRT3_ON_2 * ab[1]);
  abc[2] = -(0.5f * ab[0]) - (M_SQRT3_ON_2 * ab[1]); // Incorrectly had alpha term as positive before!
}

#endif // end of CLARKE_h defines
       

