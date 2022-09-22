//#############################################################################
//
// FILE:   utils.h
//
// TITLE:  Useful functions
//
//#############################################################################

/* Prevent recursive definition */
#ifndef UTILS_H
#define UTILS_H


//#ifdef __cplusplus
//extern "C" {
//#endif

/* Includes */
#include "math.h"
#include "stm32g4xx.h" // For cmsis __STATIC_FORCEINLINE
#include "stm32g4xx_ll_cordic.h"

/* Useful constants */
#define M_1_Q31         4.656612873077392578125e-10f // 1/2^31
#define M_Q31_PI        6.8356527557643158978229477811035e8f  // 2^31/pi
#define M_PI_Q31        1.4629180792671596810513378043098e-9f // pi/2^31
#define M_Q31           2147483648.0f // 2^31
#define M_ONE_ON_SQRT3  0.577350269189626f
#define M_TWO_ON_SQRT3  1.154700538379252f
#define alpha_sf        1.0f / 3.0f
#define M_SQRT3_ON_2    0.866025403784439f
#define beta_sf         M_ONE_ON_SQRT3
#define kelvin          273.15f
#define invT0           (float)(1.0f / 298.15f)

/* In place truncation of float to between min and max */
__STATIC_INLINE void fsat(volatile float *num, float min, float max)
{
  if (*num > max) {
    *num = max;
  } else if (*num < min) {
    *num = min;
  }
}

/* Normalize an angle in radians to between -pi and pi */

__STATIC_INLINE void norm_angle(volatile float *angle)
{
  while (*angle < -M_PI) { *angle += 2.0 * M_PI; }
  while (*angle >=  M_PI) { *angle -= 2.0 * M_PI; }
}

/*  Calculate sine and cosine using CORDIC peripheral
    Input angle should be normalized radians between -pi and pi.
    Out of range input values will be saturated and produce incorrect results.
    CORDIC config register is written during every operation.
    TODO: Be more efficient by not calling the config if the CORDIC peripheral
    is already correctly configured (e.g when calculating multiple sine/cosine). 
    */
__STATIC_INLINE void cordic_sincos(volatile float angle, float *sin, float *cos)
{
  int cordic_input = (int)(angle * M_Q31_PI);
  LL_CORDIC_Config(CORDIC, 
                  LL_CORDIC_FUNCTION_SINE, 
                  LL_CORDIC_PRECISION_6CYCLES, // 4 iterations per cycle for maximum 24 iteration precision
                  LL_CORDIC_SCALE_0,           // Result scaling not applicable
                  LL_CORDIC_NBWRITE_1,         // One 32 bit input for angle. No modulus argument for sin and cos.
                  LL_CORDIC_NBREAD_2,            // Two output data - sine then cosine
                  LL_CORDIC_INSIZE_32BITS,      // q1.31 format for input data
                  LL_CORDIC_OUTSIZE_32BITS);     // q1.31 format for input data
  LL_CORDIC_WriteData(CORDIC, cordic_input);
  *sin = (float)((int)LL_CORDIC_ReadData(CORDIC)) * M_1_Q31;
  *cos = (float)((int)LL_CORDIC_ReadData(CORDIC)) * M_1_Q31;
}

/*  Calculate atan2 phase using CORDIC peripheral
    Input coordinates should be scaled within range -1 to 1, with max input modulus 1.
    E.g [1,1] will be out of range and produce incorrect results even if coordinates are valid inputs. 
    CORDIC config register is written during every operation!
    */
__STATIC_INLINE void cordic_atan2(volatile float x, volatile float y, volatile float *theta)
{
  /* Convert float input to q31 */
  int x_arg = (int)(x * M_Q31_PI);
  int y_arg = (int)(y * M_Q31_PI);

  /* Configure and trigger CORDIC */
  LL_CORDIC_Config(CORDIC, 
                  LL_CORDIC_FUNCTION_PHASE, 
                  LL_CORDIC_PRECISION_6CYCLES, // 4 iterations per cycle for maximum 24 iteration precision
                  LL_CORDIC_SCALE_0,           // Result scaling not applicable
                  LL_CORDIC_NBWRITE_2,         // Two 32-bit input args
                  LL_CORDIC_NBREAD_1,            // One 32-bit result transferred to result register. Discard modulus result. 
                  LL_CORDIC_INSIZE_32BITS,      // q1.31 format for input data
                  LL_CORDIC_OUTSIZE_32BITS);     // q1.31 format for output data
  LL_CORDIC_WriteData(CORDIC, x_arg);
  LL_CORDIC_WriteData(CORDIC, y_arg);
  

  /* Convert result from q31 to float with range -pi to pi */
  *theta = (float)((int)LL_CORDIC_ReadData(CORDIC)) * M_PI_Q31;
}

/* Vesc fast_sincos_better() function used in mcpwmfoc.c */
void vesc_fast_sincos(float angle, float *sin, float *cos);

/*  Convert float to q31 fixed point
    \param  pSrc    The pointer to input float between -1 and 1
    \param  pDst    The pointer to an unsigned int holding the q31 */
__STATIC_INLINE void float_to_q31(float *pSrc, int *pDst)
{
  *pDst = (uint32_t)(*pSrc * 2147483648.0f);
}

#endif // End of utils.h defines
