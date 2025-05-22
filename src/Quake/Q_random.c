
float Q_random( int *seed )
{
	return ( ( Q_rand( seed ) & 0xffff ) / (float)0x10000 );
}