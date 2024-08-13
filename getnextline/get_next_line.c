/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:21:30 by shachan           #+#    #+#             */
/*   Updated: 2024/08/14 00:47:16 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// read and store the text in an array
static char	*ft_read_and_store(int fd, char *store)
{
	int		char_read;
	char	*buf;
	char	*temp;

	if (store == NULL)
		store = ft_calloc(1, sizeof(char));
	printf("1st store in ft_read_and store:%s\n", store);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	// char_read = read(fd, buf, BUFFER_SIZE);
	// printf("char read:%d\n", char_read);
	printf("1st buf in ft_read_and_store:%s\n", buf);
	while (char_read > 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		printf("char read in ft_print_and_store:%d\n", char_read);
		buf[char_read] = '\0';
		temp = ft_strjoin(store, buf);
		printf("temp:%s\n", temp);
		free (store);
		store = temp;
		printf("2nd store in ft_read_and_store:%s\n\n", store);
		if (store == NULL)
			return (NULL);
		// if (ft_strchr(store, '\n'))
		// 	break ;
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

	// printf("store: %s\n", store);
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
		// printf("1st store in ft_find_next_line:%s\n", store);
		// printf("next line: %s", find_next_line);
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

int	main(void)
{
	int fd;
	char *s;

	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("line 1: %s\n", s);
	free(s);

	s = get_next_line(fd);
	printf("line 2: %s\n", s);
	free(s);
	
	close(fd);
	return(0);
}