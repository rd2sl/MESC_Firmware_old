/*
* Copyright 2021 cod3b453
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice, this
*    list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MESC_SPEED_H
#define MESC_SPEED_H

#include <inttypes.h>

#define SPEED_PROFILE_SIGNATURE MAKE_UINT32_STRING('M','S','P','E')

#define NUM_HALL_STATES (UINT32_C(6))

struct SPEEDProfile
{
    struct
    {
    float       Imax;       // Amp
    float       Vmax;       // Volt
    float       Pmax;       // Watt
    uint32_t    RPMmax;
    uint8_t     pole_pairs;
    uint8_t     direction;
    uint8_t     allow_regen;
    uint8_t     _;
    }           motor;

    struct
    {
    uint8_t     type;
    uint8_t     hall_states[NUM_HALL_STATES];
    uint8_t     _;
    }           sensor;

    struct
    {
    uint32_t    motor;      // Teeth on motor
    uint32_t    wheel;      // Teeth on wheel
    }           gear_ratio; // Use 1:1 for no gear ratio

    struct
    {
    float       diameter;   // In wheel size units (inches/centimetres)
    float       conversion; // Conversion from wheel size units to speedometer units (miles/kilometres per hour)
    }           wheel;

};

typedef struct SPEEDProfile SPEEDProfile;

void speed_init( SPEEDProfile const * const profile );

void speed_register_vars( float const * const drev, float const * const dt );

float speed_get( void );

#endif
