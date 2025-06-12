#include <stdbool.h>

int my_sign( int x )
{
	return ( ( x >= 0 ) - ( x < 0 ) );
}

bool have_opposite_signs( int x, int y )
{
	return ( ( x ^ y ) < 0 );
}

bool have_same_signs( int x, int y )
{
	return ( ( x ^ y ) >= 0 );
}
