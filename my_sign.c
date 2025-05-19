// int	my_sign(int x)
// {
// 	return ((x > 0) - (x < 0));
// }

// Version plus optimisée
int	my_sign(int x)
{
	return ((x >> 31) | (!!x));
}
