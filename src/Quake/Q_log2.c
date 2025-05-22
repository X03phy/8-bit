#include <stdint.h> // int16_t

int16_t Q_log2( int16_t x )
{
	int16_t answer;

	answer = 0;
	while ( (answer >>= 1) != 1 )
		answer++;

	return ( answer );
}
