/*
 * Copyright (c) 2007, 2009 Joseph Gaeddert
 * Copyright (c) 2007, 2009 Virginia Polytechnic Institute & State University
 *
 * This file is part of liquid.
 *
 * liquid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * liquid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with liquid.  If not, see <http://www.gnu.org/licenses/>.
 */

//
//
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "liquid.internal.h"

// Weibull
float randweibf(float _alpha,
                float _beta,
                float _gamma)
{
#ifdef LIQUID_VALIDATE_INPUT
    // validate input
    if (_alpha <= 0) {
        fprintf(stderr,"error: randweibf(), alpha must be greater than zero\n");
        return 0.0f;
    } else if (_beta <= 0) {
        fprintf(stderr,"error: randweibf(), beta must be greater than zero\n");
        return 0.0f;
    }
#endif

    return _gamma + powf(-_beta/_alpha*logf(randf()), 1/_beta);
}

// Weibull random number probability distribution function
float randweibf_pdf(float _x,
                    float _alpha,
                    float _beta,
                    float _gamma)
{
#ifdef LIQUID_VALIDATE_INPUT
    // validate input
    if (_alpha <= 0) {
        fprintf(stderr,"error: randweibf(), alpha must be greater than zero\n");
        return 0.0f;
    } else if (_beta <= 0) {
        fprintf(stderr,"error: randweibf(), beta must be greater than zero\n");
        return 0.0f;
    }
#endif

    if (_x < _gamma)
        return 0.0f;

    float t = _x - _gamma;
    return _alpha * powf(t,_beta-1.0f) * expf( -_alpha/_beta * powf(t,_beta) );
}

// Weibull random number cumulative distribution function
float randweibf_cdf(float _x,
                    float _alpha,
                    float _beta,
                    float _gamma)
{
#ifdef LIQUID_VALIDATE_INPUT
    // validate input
    if (_alpha <= 0) {
        fprintf(stderr,"error: randweibf(), alpha must be greater than zero\n");
        return 0.0f;
    } else if (_beta <= 0) {
        fprintf(stderr,"error: randweibf(), beta must be greater than zero\n");
        return 0.0f;
    }
#endif

    return 0.0f;
}

