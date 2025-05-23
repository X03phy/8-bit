#include <stdint.h> // int32_t

float Q_rsqrt( float x )
{
	int32_t i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = x * 0.5F;
	y = x;
	i = * ( int32_t * ) &y;                    // evil floating point bit level hacking
	i = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y = * ( float * ) &i;
	y = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
	y = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return ( y );
}
