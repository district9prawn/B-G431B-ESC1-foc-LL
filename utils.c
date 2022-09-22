//#############################################################################
//
// FILE:   utils.c
//
// TITLE:  Useful functions
//
//#############################################################################

#include "utils.h"

/* Vesc fast_sincos_better() function used in mcpwmfoc.c */
void vesc_fast_sincos(float angle, float *sin, float *cos)
{
	//always wrap input angle to -PI..PI
	while (angle < -M_PI) {
		angle += 2.0 * M_PI;
	}

	while (angle >  M_PI) {
		angle -= 2.0 * M_PI;
	}

	//compute sine
	if (angle < 0.0) {
		*sin = 1.27323954 * angle + 0.405284735 * angle * angle;

		if (*sin < 0.0) {
			*sin = 0.225 * (*sin * -*sin - *sin) + *sin;
		} else {
			*sin = 0.225 * (*sin * *sin - *sin) + *sin;
		}
	} else {
		*sin = 1.27323954 * angle - 0.405284735 * angle * angle;

		if (*sin < 0.0) {
			*sin = 0.225 * (*sin * -*sin - *sin) + *sin;
		} else {
			*sin = 0.225 * (*sin * *sin - *sin) + *sin;
		}
	}

	// compute cosine: sin(x + PI/2) = cos(x)
	angle += 0.5 * M_PI;
	if (angle >  M_PI) {
		angle -= 2.0 * M_PI;
	}

	if (angle < 0.0) {
		*cos = 1.27323954 * angle + 0.405284735 * angle * angle;

		if (*cos < 0.0) {
			*cos = 0.225 * (*cos * -*cos - *cos) + *cos;
		} else {
			*cos = 0.225 * (*cos * *cos - *cos) + *cos;
		}
	} else {
		*cos = 1.27323954 * angle - 0.405284735 * angle * angle;

		if (*cos < 0.0) {
			*cos = 0.225 * (*cos * -*cos - *cos) + *cos;
		} else {
			*cos = 0.225 * (*cos * *cos - *cos) + *cos;
		}
	}
}

