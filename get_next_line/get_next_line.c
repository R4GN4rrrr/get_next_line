/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 04:23:52 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/11/19 03:36:18 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_add_join(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_rest(save);
	return (line);
}
// int main()
// {
// 	int fd = open("t.html", O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// }// 