#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1, char X)
{
	int		i;
	char	*p;

	i = 1;
	if (s1[i] != '\0')
	{
		while (s1[i] && s1[i] != 'X')
			i++;
		p = malloc(sizeof(char) * i + 1);
		if (p == NULL)
			return (NULL);
		i = 0;
		while (s1[i] != '\0' && s1[i] != 'X')
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
	}
	else
	{
		p = malloc(sizeof(char));
		p[i] = '\0';
	}
	return ((char *)p);
}
int main()
{
	const char str[] = "shut up and $take my money";
	printf("%s",ft_strdup(str, '$'));
}
