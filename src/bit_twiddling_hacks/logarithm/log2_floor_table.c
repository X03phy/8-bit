
unsigned int log2_floor_table( unsigned int v )
{
	static const char LogTables256[256] = 
	{
		#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n
		-1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
		LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
		LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
	};
	register unsigned int t, tt;

	if ( tt = ( v >> 16 ) )
		return ( ( t = ( tt >> 8 ) ) ? ( 24 + LogTables256[t] ) :  ( 16 + LogTables256[tt] ) );
	else
		return ( ( t = ( v >> 8 ) ) ? ( 8 + LogTables256[t] ) :  ( LogTables256[v] ) );
}
