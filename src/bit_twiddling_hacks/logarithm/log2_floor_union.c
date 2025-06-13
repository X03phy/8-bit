/*
Prototype:
	unsigned int log2_floor_union( unsigned int v );

Description:
	Finds the integer value of log2( v ), meaning: floor( log2( v ) ).

Arguments:
	unsigned int v : the value whose base-2 logarithm we want to compute.

Return:
	unsigned int : the floor of log2( v ) (i.e., the position of the highest bit set).

How it works:
	We use a union that shares memory between:
		- a double (64-bit IEEE 754 floating-point)
		- an array of two unsigned int (2 × 32-bit = 64 bits)

	Goal: store (2^52 + v) in the double field.
	Why 2^52?
		Because 2^52 is the smallest power of 2 for which all integer values ≤ 2^32
		are exactly representable in double precision.

	Step by step:
	1. Set the high part of the double to 0x43300000 → this sets the exponent to 1023 + 52 = 1075
	2. Set the low part to v (the integer we want to get log2 of)
	3. The result is: d = 2^52 + v
	4. Subtract 2^52 from d → result is d = v (in exact double format)
	5. The exponent part of the resulting double represents log2( v )
	6. Extract the exponent bits, shift right 20, and subtract 1023 (the bias)

Example:
	v = 64

	t.d = 2^52 + 64 = 4503599627370560.0
	t.d -= 2^52 = 64.0
	extract exponent:
		exponent_bits = ( t.u[1] >> 20 ) = 1029
		1029 - 1023 = 6

	So: log2(64) = 6 → result is 6

Notes:
	This technique avoids calling any math library function.
	It is extremely fast and safe for all 32-bit unsigned ints.
*/

#include <endian.h>
// Pour un double: valeur = ±mantisse × 2^(exposant - 1023)

unsigned int log2_floor_union( unsigned int v )
{
	union { unsigned int u[2]; double d; } t; // temp

	t.u[__FLOAT_WORD_ORDER == __LITTLE_ENDIAN] = 0x43300000; // --> d = 2^52
	t.u[__FLOAT_WORD_ORDER != __LITTLE_ENDIAN] = v; // d = 2^52 + v
	t.d -= 4503599627370496.0;

	return ( ( t.u[__FLOAT_WORD_ORDER == __LITTLE_ENDIAN] >> 20 ) - 0x3FF );
}
