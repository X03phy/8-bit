#include <stddef.h>
#include <stdio.h>

// Architecture 64-bits
size_t	my_strlen(const char *str)
{
	const char	*char_ptr;
	const unsigned long int	*longword_ptr;
	unsigned long int	longword, himagic, lomagic;

	for (char_ptr = str; ((unsigned long int)char_ptr & 7) != 0; char_ptr++)
		if (*char_ptr == '\0')
			return (char_ptr - str);

	longword_ptr = (unsigned long int *)char_ptr;
	lomagic = 0x0101010101010101UL;
	himagic = 0x8080808080808080UL;
	for(;;)
	{
		
	}
	return (char_ptr - str);
}

int	main( void )
{
	size_t	a = my_strlen("Elio");
	printf("%lu\n", a);
	return (0);
}
