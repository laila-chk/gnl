/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:40:19 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/12 04:45:52 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>


/* just increment the damned string and re calculate X after passing the whole buf to str */
/* there will be a str that points to buf, static, it stops by \n */
void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write (1, s, 1);
		s++;
	}
}

//#ifdef BUFFER_SIZE
#define BUFFER_SIZE 1000
static size_t sz = BUFFER_SIZE; 
char *minitest(int fd)
{
	char buf[BUFFER_SIZE + 1];
	int ret ;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)	
	{
		read(fd, buf, BUFFER_SIZE);
		sz++;
	}
	buf[sz] = '\0';
	printf("%d\n", ret);
	printf("%zu\n", sz);
	printf("%d\n", BUFFER_SIZE);
	printf("%s", buf);
	return (buf);
}
/*i'm kinda sleepy i just can't now, the idea is adding a static str that points into buf, it is easy to print from it until we face a \n and increment it using ++ , since it is static i fairly believe i ain't gonna find a prb with moving to the next line kay bye now */
//#endif
int main()
{
	int fd = open("random.txt", O_RDONLY);
	minitest(fd);
}
