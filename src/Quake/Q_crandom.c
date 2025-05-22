#include <stdint.h> // int16_t

float Q_crandom( int16_t *seed )
{
	return ( 2.0 * ( Q_random( seed ) - 0.5 ) );
}
