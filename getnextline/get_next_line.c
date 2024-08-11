/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:21:30 by shachan           #+#    #+#             */
/*   Updated: 2024/08/12 02:15:11 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read and store the text in an array
static char	*ft_read_and_store(int fd, char *store)
{
	int		char_read;
	char	*buf;
	char	*temp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	char_read = read(fd, buf, BUFFER_SIZE);
	while (char_read > 0)
	{
		buf[char_read] = '\0';
		temp = ft_strjoin(store, buf);
		free (store);
		store = temp;
		if (store == NULL)
			return (NULL);
		if (ft_strchr(store, '\n'))
			break ;
	}
	if (char_read < 0)
	{
		free (store);
		return (NULL);
	}
	return (store);
}

//copy everything before '\n' into an array to print, and update store array
static char	*ft_find_next_line(char *store)
{
	char	*find_next_line;
	char	*tmp;
	int		i;
	int		store_len;

	store_len = ft_strlen(store);
	i = 0;
	while ((store[i] != '\0') && (store[i] != '\n'))
		i++;
	find_next_line = malloc(sizeof(char) * (i + 2));
	if (find_next_line == NULL)
		return (NULL);
	if (store[i] == '\n')
	{
		ft_strlcpy(find_next_line, store, i + 2);
		tmp = ft_substr(store, i + 1, store_len - i - 1);
		free(store);
		store = tmp;
	}
	else
	{
		ft_strlcpy(find_next_line, store, i + 1);
		store[0] = '\0';
	}
	return (find_next_line);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*next_line;

	store = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = ft_read_and_store(fd, store);
	if (store == NULL)
		return (NULL);
	next_line = ft_find_next_line(store);
	if (next_line == NULL)
		return (NULL);
	return (next_line);
}
// #include <stdio.h>
// int	main()
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == -1)
// 			break ;
// 		printf("%s", line);
// 		free (line);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	int fd;
// 	char *s;

// 	fd = open("test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// }