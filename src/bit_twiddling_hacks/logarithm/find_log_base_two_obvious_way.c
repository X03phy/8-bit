
unsigned int find_log_base_two_obvious_way( unsigned int v )
{
	unsigned int r = 0; // r will be lg(v)

	while ( v >>= 1 ) // unroll for more speed...
	{
		++r;
	}

	return ( r );
}
