#ifndef BIT_TWIDDLING_H
#define BIT_TWIDDLING_H

// Include necessary headers

#include <stdint.h> // int32_t, int16_t
#include <stdbool.h> // bool
#include <stddef.h> // size_t

// Bit Twiddling Functions

// bit_twiddling functions

// Quake3 Arena functions
int16_t Q_rand( int16_t *seed );
float Q_random( int16_t *seed );
float Q_crandom( int16_t *seed );
float Q_fabs( float x );
int16_t Q_log2( int16_t x );
float Q_rsqrt( float x );

// string functions
size_t my_strlen( const char *str );


#endif
