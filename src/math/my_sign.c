// szas

int	my_sign(int x)
{
	return ((x >> 31) | (!!x));
}
