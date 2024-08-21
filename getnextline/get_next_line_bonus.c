/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 03:04:10 by shachan           #+#    #+#             */
/*   Updated: 2024/08/22 04:08:05 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

// add char read from buf to store
static char	*ft_add_to_store(char *store, char *buf)
{
	char	*temp;

	if (store == NULL)
		store = ft_strjoin("", buf);
	else
	{
		temp = ft_strjoin(store, buf);
		free(store);
		store = ft_strjoin("", temp);
		free(temp);
	}
	return (store);
}

// read and store the text in an array
static char	*ft_read_and_store(int fd, char *store)
{
	int		char_read;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	char_read = read(fd, buf, BUFFER_SIZE);
	while (char_read > 0)
	{
		buf[char_read] = '\0';
		store = ft_add_to_store(store, buf);
		if (ft_strchr(store, '\n'))
			break ;
		char_read = read(fd, buf, BUFFER_SIZE);
	}
	free (buf);
	if (store == NULL)
		return (NULL);
	if ((char_read == -1) || (store[0] == '\0'))
	{
		free(store);
		return (NULL);
	}
	return (store);
}

static char	*ft_extract_next_line(char *store)
{
	char	*next_line;
	int		break_index;

	break_index = 0;
	while ((store[break_index] != '\0') && (store[break_index] != '\n'))
		break_index++;
	if (store == NULL)
		return (NULL);
	if ((break_index == 0) && (store[0] != '\0') && (store[0] != '\n'))
		break_index = ft_strlen(store);
	next_line = malloc(sizeof(char) * (break_index + 2));
	if (next_line == NULL)
		return (NULL);
	next_line = ft_substr(store, 0, break_index + 1);
	return (next_line);
}

static char	*ft_update_store(char *store)
{
	char	*tmp;
	int		store_len;
	int		break_index;

	break_index = 0;
	while ((store[break_index] != '\0') && (store[break_index] != '\n'))
		break_index++;
	store_len = ft_strlen(store);
	if (store[break_index] == '\0')
	{
		free(store);
		return (NULL);
	}
	tmp = ft_substr(store, break_index + 1, store_len - break_index);
	free(store);
	store = ft_strjoin("", tmp);
	free(tmp);
	tmp = NULL;
	return (store);
}

char	*get_next_line(int fd)
{
	static char	**store;
	char		*next_line;

	if (store == NULL)
	{
		store = malloc(sizeof(char *) * (NUM_FD + 1));
		if (store == NULL)
			return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= NUM_FD)
	{
		ft_free_store(store);
		store = NULL;
		return (NULL);
	}
	store[fd] = ft_read_and_store(fd, store[fd]);
	if (store[fd] == NULL)
		return (NULL);
	next_line = ft_extract_next_line(store[fd]);
	if (next_line == NULL)
		return (NULL);
	store[fd] = ft_update_store(store[fd]);
	return (next_line);
}

int	main(void)
{
	int 	fd;
	int		fd2;
	char	*s;
	char	*t;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);

	s = get_next_line(fd);
	printf("line 1 of fd1: |%s|\n", s);
	free(s);
	t = get_next_line(fd2);
	printf("line 1 of fd2: |%s|\n", t);
	free(t);

	s = get_next_line(fd);
	printf("line 2 of fd1: |%s|\n", s);
	free(s);
	t = get_next_line(fd2);
	printf("line 2 of fd2: |%s|\n", t);
	free(t);

	s = get_next_line(fd);
	printf("line 3 of fd1: |%s|\n", s);
	free(s);
	t = get_next_line(fd2);
	printf("line 3 of fd2: |%s|\n", t);
	free(t);

	s = get_next_line(fd);
	printf("line 4 of fd1: |%s|\n", s);
	free(s);
	t = get_next_line(fd2);
	printf("line 4 of fd2: |%s|\n", t);
	free(t);

	s = get_next_line(fd);
	printf("line 5 of fd1: |%s|\n", s);
	free(s);
	t = get_next_line(fd2);
	printf("line 5 of fd2: |%s|\n", t);
	free(t);

	// s = get_next_line(fd);
	// printf("line 6 of fd1: |%s|\n", s);
	// free(s);
	// t = get_next_line(fd2);
	// printf("line 6 of fd2: |%s|\n", t);
	// free(t);

	close(fd);
	close(fd2);
	return(0);
}
