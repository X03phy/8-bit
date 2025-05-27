#include <stdbool.h>

int my_sign( int x ) // -5
{
	return ( ( x >> 31 ) | ( x ) );
}

bool have_opposite_signs( int x, int y )
{
	return ( ( x ^ y ) < 0 );
}

bool have_same_signs( int x, int y )
{
	return ( ( x ^ y ) >= 0 );
}


int main(int argc, char const *argv[])
{
	if (  )
	return 0;
}
