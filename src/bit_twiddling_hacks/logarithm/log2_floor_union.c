#include <endian.h>
// Pour un double: valeur = ±mantisse × 2^(exposant - 1023)

unsigned int log2_floor_union( unsigned int v )
{
	union { unsigned int u[2]; double d; } t; // temp

	t.u[__FLOAT_WORD_ORDER == __LITTLE_ENDIAN] = 0x43300000; // --> d = 2^52
	t.u[__FLOAT_WORD_ORDER != __LITTLE_ENDIAN] = v; // d = 2^52 + 64
	t.d -= 4503599627370496.0;

	return ( ( t.u[__FLOAT_WORD_ORDER == __LITTLE_ENDIAN] >> 20 ) - 0x3FF );
}
