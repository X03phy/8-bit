#include <stdint.h> // int16_t

int16_t Q_rand( int16_t *seed )
{
	*seed = ( 69069 * *seed + 1 );
	return ( *seed );
}
