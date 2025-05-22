#include <stdint.h> // int16_t

float Q_random( int16_t *seed )
{
	return ( ( Q_rand( seed ) & 0xffff ) / (float)0x10000 );
}