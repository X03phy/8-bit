

int Q_log2( int x )
{
	int answer;

	answer = 0;
	while ( (answer >>= 1) != 1 )
		answer++;

	return ( answer );
}
