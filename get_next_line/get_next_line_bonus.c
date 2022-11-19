/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 04:01:25 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/11/19 04:30:55 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_add_join(int fd, char *saved)
{
	int		nbyte;
	char	*buff;

	nbyte = 1;
	if (!saved)
		saved = ft_strdup("");
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while(nbyte && !ft_strchr(saved))
	{
		nbyte = read(fd, buff, BUFFER_SIZE);
		if (nbyte == - 1)
		{
			free(saved);
			free(buff);
			saved = NULL;
			return (NULL);
		}
		buff[nbyte] = '\0';
		saved = ft_strjoin(saved, buff); 
	}
	free (buff);
	return (saved);
}

char    *ft_line(char    *string)
{
	int     i;
	char	*str;

	i = 0;
	if (!*string)
		return (NULL);	
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	str = malloc((i + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
	{
		str[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		str[i] = string[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_rest(char *save)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || !save[i + 1])
	{
		free (save);
		return (NULL);
	}
	s = malloc((ft_strlen(save) - i) * sizeof(char));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	if (save[i] == '\n')
		s[j++] = save[i];
	s[j] = '\0';
	free (save);
	save = NULL;
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	save[fd] = ft_add_join(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_line(save[fd]);
	save[fd] = ft_rest(save[fd]);
	return (line);
}
// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }