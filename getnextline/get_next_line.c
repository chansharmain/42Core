/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:21:30 by shachan           #+#    #+#             */
/*   Updated: 2024/08/25 02:05:03 by shachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// add char read from buf to store
static char	*ft_add_to_store(char *store, char *buf)
{
	char	*temp;

	if (store == NULL)
	{
		store = ft_strjoin("", buf);
		if (store == NULL)
			return (NULL);
	}
	else
	{
		temp = ft_strjoin(store, buf);
		free(store);
		if (temp == NULL)
			return (NULL);
		store = ft_strjoin("", temp);
		free(temp);
		if (store == NULL)
			return (NULL);
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
		return (free(store), NULL);
	char_read = read(fd, buf, BUFFER_SIZE);
	while (char_read > 0)
	{
		buf[char_read] = '\0';
		store = ft_add_to_store(store, buf);
		if (store == NULL)
			return (free(buf), NULL);
		if (ft_strchr(store, '\n'))
			break ;
		char_read = read(fd, buf, BUFFER_SIZE);
	}
	free (buf);
	if ((char_read == -1) || (store != NULL && store[0] == '\0'))
		return (free(store), NULL);
	return (store);
}

static char	*ft_extract_next_line(char *store)
{
	char	*next_line;
	int		break_index;

	if (store == NULL)
		return (NULL);
	break_index = 0;
	while ((store[break_index] != '\0') && (store[break_index] != '\n'))
		break_index++;
	if ((break_index == 0) && (store[0] != '\0') && (store[0] != '\n'))
		break_index = ft_strlen(store);
	next_line = ft_substr(store, 0, break_index + (store[break_index] == '\n'));
	if (next_line == NULL)
		return (NULL);
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
	if (tmp == NULL)
		return (NULL);
	store = ft_strjoin("", tmp);
	free(tmp);
	tmp = NULL;
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = ft_read_and_store(fd, store);
	if (store == NULL)
		return (NULL);
	next_line = ft_extract_next_line(store);
	if (next_line == NULL)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	store = ft_update_store(store);
	return (next_line);
}

// int	main(void)
// {
// 	int fd;
// 	char *s;

// 	fd = open("test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("line 1: |%s|\n", s);
// 	free(s);

// 	s = get_next_line(fd);
// 	printf("line 2: |%s|\n", s);
// 	free(s);

//  s = get_next_line(fd);
// 	printf("line 3: |%s|\n", s);
// 	free(s);

// 	s = get_next_line(fd);
// 	printf("line 4: |%s|\n", s);
// 	free(s);

// 	s = get_next_line(fd);
// 	printf("line 5: |%s|\n", s);
// 	free(s);

// 	// s = get_next_line(fd);
// 	// //printf("line 6: |%s|\n", s);
// 	// free(s);

// 	close(fd);
// 	return(0);
// }