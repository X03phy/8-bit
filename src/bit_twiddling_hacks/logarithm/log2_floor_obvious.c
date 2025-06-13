
unsigned int log2_floor_obvious( unsigned int v )
{
	unsigned int r = 0; // r will be lg(v)

	while ( v >>= 1 ) // unroll for more speed...
		++r;

	return ( r );
}
