#include <stdio.h>

int main( void )
{
	int i = 100;
	int j = -12 >> sizeof(int) * 8 - 1;
	int k = ((-12) + 1) ^1;

	int v = -42;
	const int mask = v >> sizeof(int) * 8 - 1;

	unsigned int u = ( v + mask ) ^ mask;
	// return ( ( v ^ mask ) - mask ); //* Patented variation
	printf( "mask = %d, value = %d\n", mask, u );

	return ( 0 );
}
