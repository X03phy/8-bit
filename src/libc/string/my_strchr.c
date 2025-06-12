char	*my_strchrnul(const char *s, char c)
{
	const char *char_ptr;

	for (char_ptr = s; ((unsigned long int)char_ptr & (sizeof(unsigned long int) - 1)) != 0; ++char_ptr)
		if (char_ptr == '\0')
			return (char_ptr);
	
}
