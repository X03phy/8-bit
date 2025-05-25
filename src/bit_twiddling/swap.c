#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP_XOR_UNSAFE(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))
#define SWAP_XOR_SAFE(a, b) ((&(a) == &(b)) || (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b))))
#define SWAP_XOR_RESEARCH(a, b) (((a) ^ (b)) && ((b) ^= (a) ^= (b), (a) ^= (b)))

void swap_tmp( int *x, int *y )
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap_xor( int *x, int *y )
{
	if ( x != y )
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

void swap_add( int *x, int *y )
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void swap_sub( int *x, int *y )
{
	*x = *x - *y;
	*y = *x + *y;
	*x = *y - *x;
}
