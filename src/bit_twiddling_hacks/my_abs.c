/*
Prototype:
	unsigned int my_abs( int v );

Description:
	Converts an integer to its positive form.

Arguments:
	int : the value to convert.

Return:
	unsigned int : The positive value.

How it works:
	We use a mask to convert our value.
	The mask is equal to -1 if the value is negative, or 0 if it is positive.
	Why -1 ? Because the sign bit is copied due to the >> operator.

	Case 0:
		( v + mask ) ^ mask == v ( by definition of ^ )
	Case -1:
		( v + mask ) ^ mask == ( v - 1 ) ^ ( -1 )

Example:
	v = ( -42 ) -> 11111111 11111111 11111111 11010110
	mask = v >> 31 ( 32 bits int ) -> 11111111 11111111 11111111 11111111

	v + mask == ( -42 ) + ( -1 ) == ( -42 ) - 1 == ( -43 ) -> 11111111 11111111 11111111 11010101
	( v + mask ) ^ mask == ( -43 ) ^ ( -1 ):
		11111111 11111111 11111111 11010101
		xor
		11111111 11111111 11111111 11111111
		==
		00000000 00000000 00000000 00101010 == 42

Notes:
	! Pour convertir un entier négatif en positif en complément à deux, on a ces 3 formules:
	! 1) ~( v ) + 1
	! 2) ( v ^ ( -1 ) ) + 1
	! 3) ( v - 1 ) ^ ( -1 )
*/

// CHAR_BIT
#include <limits.h>

unsigned int my_abs( int v )
{
	const int mask = v >> ( sizeof(int) * CHAR_BIT - 1 );

	// return ( ( v ^ mask ) - mask ); //* Patented variation
	return ( ( v + mask ) ^ mask );
}
