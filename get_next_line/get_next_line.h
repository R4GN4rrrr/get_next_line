/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 04:24:07 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/11/19 03:22:54 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
int ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_rest(char *save);
char    *ft_line(char    *string);
char	*ft_add_join(int fd, char *saved);

#endif