// // Pour size_t
// #include <stddef.h>
// // Pour UCHAR_MAX
// #include <limits.h>
// // Pour unitptr_t
// #include <stdint.h>

// // Musl libc
// #define ALIGN sizeof(size_t)                 // ALIGN = 4 (32 bits) | ALIGN = 8 (64 bits)
// #define LOMAGIC ((size_t)-1/UCHAR_MAX)          // size_t-1 = 0xFF... | UCHAR_MAX = 255 | 0xFF / 255 = 0x01
// #define HIMAGIC (LOMAGIC * (UCHAR_MAX/2+1))       // LOWS = 0x01... | UCHAR_MAX/2+1 = 255/2 + 1 = 127 + 1 = 128 | 0x01 * 128  = 0x80
// #define HASZERO(x) ((x)-LOMAGIC & ~(x) & HIMAGIC) // Ligne magique pour reperer un \0 dans 8 octets

// size_t my_strlen(const char *s)
// {
// 	const char *a;

// 	for (a = s; ((uintptr_t)a & (ALIGN-1)) != 0; ++a)
// 		if (*a == '\0')
// 			return (a - s);

// 	const uintptr_t *w;
// 	for (w = (const uintptr_t *)a; !HASZERO(*w); ++w);

// 	a = (const char *)w;
// 	for(; *a; a++);

// 	return (a - s);
// }

// // Pour size_t
// #include <stddef.h>

// // Libft
// size_t  ft_strlen(const char *str)
// {
// 	const char *s = str;

// 	while (*s++ != '\0');
// 	return (s - str - 1);
// }


// Pour size_t
#include <stddef.h>

// glibc
size_t my_strlen( const char *str )
{
	const char *char_ptr;
	const unsigned long int *longword_ptr;
	unsigned long int longword, himagic, lomagic;

	// Alignement memoire
	for ( char_ptr = str; ( ( unsigned long int ) char_ptr & ( sizeof( unsigned long int ) - 1 ) ) != 0; ++char_ptr )
		if (*char_ptr == '\0')
			return (char_ptr - str);

	// Comparaison 8 octets par 8 octets
	longword_ptr = ( unsigned long int * ) char_ptr;
	lomagic = 0x01010101L;
	himagic = 0x80808080L;
	if ( sizeof( unsigned long int ) == 8 )
	{
		lomagic = ( lomagic << 32 ) | lomagic;
		himagic = ( himagic << 32 ) | himagic;
	}
	for( ; ; )
	{
		longword = *longword_ptr++;
		// Le point clef du code est dans ce if.
		// On verifie si 1 octet au moins parmi les 8 est '\0'.
		// On ne s'occupe que du bit le plus grand.
		// Si le char est '\0', la formule nous donne [1000 0000] (!= 0), sinon il vaut [0000 0000] (==0).
		if ( ( ( longword - lomagic ) & ~longword & himagic ) != 0 )
		{
			// Comparaisons finales, char par char (octet par octet) pour trouver la position de l'octet '\0'.
			const char *cp = ( const char * ) ( longword_ptr - 1 );

			if ( cp[0] == 0 )
				return ( cp - str );
			if ( cp[1] == 0 )
				return ( cp - str + 1 );
			if ( cp[2] == 0 )
				return ( cp - str + 2 );
			if ( cp[3] == 0 )
				return ( cp - str + 3 );
			if ( cp[4] == 0 )
				return ( cp - str + 4 );
			if ( cp[5] == 0 )
				return ( cp - str + 5 );
			if ( cp[6] == 0 )
				return ( cp - str + 6 );
			// Pas besoin de cette ligne, on enleve un check.
			// if (cp[7] == 0)
			return ( cp - str + 7 );
		}
	}
}
