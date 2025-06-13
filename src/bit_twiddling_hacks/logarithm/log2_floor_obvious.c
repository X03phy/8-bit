/*
Prototype:
	unsigned int log2_floor_obvious( unsigned int v )

Description:
	Finds the integer value of log2( v ), meaning: floor( log2( v ) ).

Arguments:
	unsigned int v : the value whose base-2 logarithm we want to compute.

Return:
	unsigned int : the floor of log2( v ) (i.e., the position of the highest bit set).

How it works:
	We check the input bit by bit until it is equal to zero.
	We also skip the case when in it equal to 1.

Example:
	0010001 ( = 17 ) -> 4
	0000001 ( = 1 )  -> 1

*/

unsigned int log2_floor_obvious( unsigned int v )
{
	unsigned int r = 0; // r will be lg(v)

	while ( v >>= 1 ) // unroll for more speed...
		++r;

	return ( r );
}
