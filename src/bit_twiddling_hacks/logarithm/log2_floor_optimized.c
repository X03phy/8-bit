
unsigned int log2_floor_optimized( unsigned int v )
{
	const unsigned int b[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
	const unsigned int S[] = {1, 2, 4, 8, 16};
	register unsigned int r = 0;

	for ( int i = 4; i >= 0; --i )
	{
		if ( v & b[i] )
		{
			v >>= S[i];
			r |= S[i];
		}
	}

	return ( r );
}

// OR (IF YOUR CPU BRANCHES SLOWLY):
unsigned int log2_floor_optimized_branchless( unsigned int v )
{
	register unsigned int r;
	register unsigned int shift;

	r =     ( v > 0xFFFF ) << 4; v >>= r;
	shift = ( v > 0xFF   ) << 3; v >>= shift; r |= shift;
	shift = ( v > 0xF    ) << 2; v >>= shift; r |= shift;
	shift = ( v > 0x3    ) << 1; v >>= shift; r |= shift;
											  r |= (v >> 1);

	return ( r );
}

// OR (IF YOUR CPU BRANCHES SLOWLY):
unsigned int log2_floor_optimized_if_power_of_two( unsigned int v )
{
	static const unsigned int b[] = {0xAAAAAAAA, 0xCCCCCCCC, 0xF0F0F0F0, 0xFF00FF00, 0xFFFF0000};
	register unsigned int r = ( ( v & b[0] ) != 0 );

	for ( int i = 4; i > 0; --i ) // unroll for speed...
		r |= ( ( v & b[i] ) != 0 ) << i;

	return ( r );
}
