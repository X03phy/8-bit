// Pour size_t
#include <stddef.h>

/* strlen de base:
size_t  ft_strlen(const char *str)
{
	const char *s = str;

	while (*s++ != '\0');
	return (s - str - 1);
}
*/

// Architecture 64-bits - glibc
size_t	my_strlen(const char *str)
{
	const char	*char_ptr;
	const unsigned long int	*longword_ptr;
	unsigned long int	longword, himagic, lomagic;

    // Alignement memoire
	for (char_ptr = str; ((unsigned long int)char_ptr & 7) != 0; ++char_ptr)
		if (*char_ptr == '\0')
			return (char_ptr - str);

    // Comparaison 8 octets par 8 octets
	longword_ptr = (unsigned long int *)char_ptr;
	lomagic = 0x0101010101010101UL;
	himagic = 0x8080808080808080UL;
	for(;;)
	{
		longword = *longword_ptr++;
        /* Le point clef du code dans ce if.
        On verifie si 1 octet au moins parmi les 8 est '\0'.
        On ne s'occupe que du bit le plus grand.
        Si le char est '\0', la formule nous donne [1000 0000] (!= 0), sinon il vaut [0000 0000] (==0).
        */
		if (((longword - lomagic) & ~longword & himagic) != 0)
		{
            // Comparaisons finales, char par char (octet par octet) pour trouver la position de l'octet '\0'.
            const char *cp = (const char *)(longword_ptr - 1);
            if (cp[0] == 0)
                return (cp - str);
            if (cp[1] == 0)
                return (cp - str + 1);
            if (cp[2] == 0)
                return (cp - str + 2);
            if (cp[3] == 0)
                return (cp - str + 3);
            if (cp[4] == 0)
                return (cp - str + 4);
            if (cp[5] == 0)
                return (cp - str + 5);
            if (cp[6] == 0)
                return (cp - str + 6);
            // Pas besoin de cette ligne, on enleve un check.
            // if (cp[7] == 0)
            return (cp - str + 7);
		}
	}
}
