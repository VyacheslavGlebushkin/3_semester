#include <cstring>

int strConteins(char *a, char *str)
{
	int t = strlen(str) - strlen(a) + 1;
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < strlen(a); ++j)
		{
			if (a[j] != str[i + j])
			{
				break;
			}
			else if (j == strlen(a) - 1)
			{
				return i;
			}
		}
	}
	return -1;
}