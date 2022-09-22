//#############################################################################
//
// FILE:   pi.h
//
// TITLE:  PI controller library (floating point)
//
//#############################################################################

#ifndef PI_H
#define PI_H

/* Includes */
#include "utils.h"

/* Define PI controller object */
typedef struct PI_obj
{
  float kp;             // Controller proportional gain
  float ki;             // Controller integral gain
  float outMin;         // Minimum allowed output value
  float outMax;         // Maximum allowed output value
  float err;            // Reference - feedback
  float err_prev;       
  float integral_prev;  // Previous integral term    
  // Might be better to include the output states in the controller object?
  float out;        // Controller output
  float out_prev;   // Previous output
  float dt;         // Time step in seconds

} PI_obj;

/*  Initialize the PI controller
    \param  obj   Pointer to a PI_obj struct
    \param  dt    Controller time step in seconds
*/
extern void PI_init(PI_obj *obj, float kp, float ki,
                    float outMin, float outMax, float dt);

/*  Run the parallel form of PI controller using simple Tustin approximation
    See https://docs.simplefoc.com/pi_controller
    \param  obj   Pointer to PI controller struct
    \param  fb    Feedback value
    \param  ref   Reference value
    \param  pOut  Pointer to the controller output value
    */
__STATIC_INLINE void PI_run(PI_obj *obj, volatile float fb, volatile float ref, volatile float *pOut)
{
  float kp = obj->kp;
  float ki = obj->ki;
  float outMin = obj->outMin;
  float outMax = obj->outMax;
  float err_prev = obj->err_prev;
  float integral_prev = obj->integral_prev;
  float dt = obj->dt;
  float res_tmp;

  // Save previous error term and calculate new error
  float err = ref - fb;

  // Calculate proportional term
  float proportional = kp * err;

  // Calculate integral term (Tustin transform)
  float integral = integral_prev + ki*dt*0.5f*(err+err_prev);

  // Anti-windup by limiting integral
  fsat(&integral, -5.0f, 5.0f); // Some arbitrary value
  
  // TODO: Anti-windup by back calculation - feed back clamped/unclamped output to integrator
  
  // Calculate output
  *pOut = proportional + integral;
  fsat(pOut, outMin, outMax);

  /* Save values for next cycle */
  obj->integral_prev = integral;
  obj->err_prev = err;
}             

#endif // End of pi.h defines
