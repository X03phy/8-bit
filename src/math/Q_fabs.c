#include <stdint.h> // int32_t

float Q_fabs( float x )
{
	int32_t tmp = * ( int32_t * ) &x;
	tmp &= 0x7FFFFFFF;
	return ( * ( float * ) &tmp );
}
