
// Definition mathematique du reste
int remainder_power_of_two( int n, unsigned int s )
{
	if ( s < 31 )
	{
		int d;

		d = 1 << s;
		return ( n & ( d - 1 ) );
	}

	return ( -1 );
}

// #include <stdio.h>
// int main()
// {
// 	int n = -5; // Exemple de nombre
// 	unsigned int s = 0; // Exemple de puissance de deux

// 	int result = remainder_power_of_two(n, s);
// 	printf("Le reste de %d divise par 2^%u est: %d\n", n, s, result);

// 	return 0;
// }
