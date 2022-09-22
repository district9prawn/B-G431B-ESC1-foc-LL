/*********************************************************************
* File    : svgen.h
* Title   : Space Vector Modulation library
**********************************************************************
*/

/* Prevent recursive definition */
#ifndef SVGEN_H
#define SVGEN_H

/* Includes */
// #include "math.h"
#include "utils.h"

/*  Implement Space Vector Modulation
    Param Vabc is pointer to three phase voltages in pu
    Param Dabc is pointer to three phase duty cycles between 0 and 1
    Vabc max of 1/sqrt(3) is maximum modulation where pure sinusoidal L-L voltages are possible
    Vabc max of 2/3 yields full trapezoid */


__STATIC_INLINE void svgen_run(volatile float *Vabc, volatile float *Dabc, volatile float Vbus)
{
  float Vmax;
  float Vmin;
  float Vcom;
  float InvVbus = 1.0f / Vbus;

  /* Voltages between 0 and 1 */
  float Va = Vabc[0] * InvVbus;
  float Vb = Vabc[1] * InvVbus;
  float Vc = Vabc[2] * InvVbus;

  /* Find Vmax and Vmin */
  if(Va > Vb) 
  {
    Vmax = Va;
    Vmin = Vb;
  } 
  else 
  {
    Vmax = Vb;
    Vmin = Va;
  }

  if(Vc > Vmax) 
  {
    Vmax = Vc;
  } 
  else if (Vc < Vmin) 
  {
      Vmin = Vc;
  }
  else
  {
    // Do nothing
  }

  /* Compute common mode neutral voltage Vcom */
  Vcom = 0.5f * (Vmax + Vmin);

  /* Subtract common-mode term to give SV modulation */
  Dabc[0] = Va - Vcom;
  Dabc[1] = Vb - Vcom;
  Dabc[2] = Vc - Vcom;

  /* Constrain duty to between -0.5 and +0.5 */
  // TODO: More efficient way to do this?
  fsat(&Dabc[0], -0.5f, 0.5f);
  fsat(&Dabc[1], -0.5f, 0.5f);
  fsat(&Dabc[2], -0.5f, 0.5f);

  /* Shift duty up so it is centred around 0.5, suitable for PWM */
  Dabc[0] += 0.5f;
  Dabc[1] += 0.5f;
  Dabc[2] += 0.5f;
}

#endif


       

