
void generate_log_table256( char table[256] )
{
	table[0] = table[1] = 0;
	for ( short int i = 2; i < 256; ++i )
		table[i] = 1 + table[i / 2];
	table[0] = -1;
}
