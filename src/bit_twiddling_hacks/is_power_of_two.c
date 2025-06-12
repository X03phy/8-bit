#include <stdbool.h>

bool is_power_of_two( int v )
{
	return ( v && !( v & ( v - 1 ) ) ); // 0 n'est pas une puissance de 2 donc on gere ce cas.
}
