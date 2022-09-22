//#############################################################################
//
// FILE:   pi.c
//
// TITLE:  PI controller library (floating point)
//
//#############################################################################

#include "pi.h"

/*  Initialize the PI controller
    \param  obj   Pointer to a PI_obj struct
    \param  dt    Controller time step in seconds
*/  
void PI_init(PI_obj *obj, float kp, float ki,
            float outMin, float outMax, float dt)
{
  obj->kp = kp;
  obj->ki = ki;
  obj->outMin = outMin;
  obj->outMax = outMax;
  obj->err = 0;
  obj->err_prev = 0;
  obj->integral_prev = 0;
  obj->out = 0;
  obj->out_prev = 0;
  obj->dt = dt;
}

