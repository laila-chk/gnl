/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:40:19 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/15 11:32:50 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10 
//#ifdef BUFFER_SIZE

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p;

	i = 1;
	if (s1[i] != '\0')
	{
		while (s1[i])
			i++;
		p = malloc(sizeof(char) * i + 1);
		if (p == NULL)
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
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

char	*ft_strdup(const char *s1, char X)
{
	int		i;
	char	*p;

	i = 1;
	if (s1[i] != '\0')
	{
		while (s1[i] && s1[i] != X)
			i++;
		p = malloc(sizeof(char) * i + 1);
		if (p == NULL)
			return (NULL);
		i = 0;
		while (s1[i] != '\0' && s1[i - 1] != X)
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

char *get_next_line(int fd)
{
	char *buf;
	char *toret;
	static char	*saved;
	int	ret;
	int	i;

	buf = (char)malloc((BUFFER_SIZE + 1) * sizeof(char));
	saved = (char)malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	while (buf[i] != '\0')
	{
		saved[i] = buf[i];
		i++;
	}
	saved[i] = '\0';
	while (strchr(saved, '\n') == 0 && ret != 0)
	{
		free (buf);
		buf = NULL;
		read(fd, buf, BUFFER_SIZE);
		saved = ft_strjoin(saved, buf);
	}
	if (strchr(saved, '\n') == 1)
		toret = ft_srtdup(saved, '\n');//returns a string that's allocated in heap, it haave to be freed that's why i decided to make toret static as well so i can free it at the beggening if it points on smth.
	saved = ft_strchr('\n');
}

int main()
{
	int fd = open("random.txt", O_RDONLY);
	get_next_line(fd);
	//	printf("**%s**",get_next_line(fd));
}
