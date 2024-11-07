/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:28:33 by barbizu-          #+#    #+#             */
/*   Updated: 2022/05/04 11:29:22 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_next(char *s)
{
	int		cnt;
	int		i;
	char	*line;

	cnt = 0;
	while (s[cnt] && s[cnt] != '\n')
		cnt++;
	if (s[cnt] == '\0')
	{
		free(s);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(s) - cnt + 1), sizeof(char));
	i = 0;
	cnt++;
	while (s[cnt])
	{
		line[i] = s[cnt];
		i++;
		cnt++;
	}
	free(s);
	return (line);
}

char	*ft_line(char *s)
{
	char	*line;
	int		cnt;

	cnt = 0;
	if (!s[cnt])
		return (NULL);
	while (s[cnt] && s[cnt] != '\n')
		cnt++;
	line = ft_calloc((cnt + 2), sizeof(char));
	cnt = 0;
	while (s[cnt] && s[cnt] != '\n')
	{
		line[cnt] = s[cnt];
		cnt++;
	}
	if (s[cnt] && s[cnt] == '\n')
		line[cnt] = '\n';
	cnt++;
	line[cnt] = '\0';
	return (line);
}

char	*ft_read(int fd, char *s)
{
	char	*buffer;
	int		read_out;
	char	*temp;

	if (!s)
		s = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_out = 1;
	while (!ft_strchr(buffer, '\n') && read_out > 0)
	{
		read_out = read(fd, buffer, BUFFER_SIZE);
		if (read_out == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_out] = '\0';
		temp = ft_strjoin(s, buffer);
		free(s);
		s = temp;
	}
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	line = ft_line(s);
	s = ft_next(s);
	return (line);
}
