

int Q_rand( int *seed )
{
	*seed = ( 69069 * *seed + 1 );
	return ( *seed );
}
