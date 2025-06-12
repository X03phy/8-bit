#include <stdio.h>

/*
	union { unsigned int u[2]; double d; } t; // temp

	t.u[__FLOAT_WORD_ORDER == LITTLE_ENDIAN] = 0x43300000;
	t.u[__FLOAT_WORD_ORDER != LITTLE_ENDIAN] = v;
	t.d -= 4503599627370496.0;

	return ( ( t.u[__FLOAT_WORD_ORDER == LITTLE_ENDIAN] >> 20 ) - 0x3FF );
*/

#include <endian.h>

#include <stdio.h>

/*
	union { unsigned int u[2]; double d; } t; // temp

	t.u[__FLOAT_WORD_ORDER == LITTLE_ENDIAN] = 0x43300000;
	t.u[__FLOAT_WORD_ORDER != LITTLE_ENDIAN] = v;
	t.d -= 4503599627370496.0;

	return ( ( t.u[__FLOAT_WORD_ORDER == LITTLE_ENDIAN] >> 20 ) - 0x3FF );
*/

#include <endian.h>

#include <stdio.h>
#include <stdint.h>
#include <endian.h>

void print_binary(double d)
{
   uint64_t b = *(uint64_t*)&d;
   for (int i = 63; i >= 0; --i)
   {
      printf("%d", (int)((b >> i) & 1));
      if (i % 8 == 0 && i != 0)  // ajoute un séparateur après chaque octet sauf le dernier
         printf(" ");
   }
   printf("\n");
}

int main( void )
{

	int v = 64;
	union { unsigned int u[2]; double d; } t; // temp

	t.u[__FLOAT_WORD_ORDER == __LITTLE_ENDIAN] = 0x43300000;
	printf( "1\n%f\n", t.d );
	print_binary( t.d );
	t.u[__FLOAT_WORD_ORDER != __LITTLE_ENDIAN] = v;
	printf( "2\n%f\n", t.d );
	print_binary( t.d );
	t.d -= 4503599627370496.0;
	printf( "3\n%f\n", t.d );
	print_binary( t.d );

	union { unsigned int u[2]; double d; } s; // temp
	s.u[__FLOAT_WORD_ORDER != __LITTLE_ENDIAN] = v;
	printf( "4\n%f\n", s.d );
	print_binary( s.d );
	return ( 0 );
}
