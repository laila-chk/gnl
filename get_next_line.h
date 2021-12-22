/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:28:37 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/21 21:15:56 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

char	*free_it(char **ptr, char **pt);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1, char X);
char	*ft_strjoin(char **s1, char *s2);
char	*get_next_line(int fd);

#endif
