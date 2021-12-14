#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' )
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	int		j;
	int		tfo;

	j = 0;
	i = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		tfo = 0;
	else
		tfo = ft_strlen(s1);
	str = malloc(tfo + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (i < tfo + ft_strlen(s2))
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j])
			str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

int main()
{
	const char *saveme;
	const char hell[] = "nawww nah";
	printf("%s",ft_strjoin(&saveme, hell));
}
