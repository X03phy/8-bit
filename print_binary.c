
#include <stdio.h>
void print_binary( char c )
{
	for (int i = 7; i >= 0; --i)
		printf("%d\n", (c >> i));
	printf("\n");
}
