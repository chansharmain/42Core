/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachan <shachan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:21:30 by shachan           #+#    #+#             */
/*   Updated: 2024/08/19 02:40:41 by shachan          ###   ########.fr       */
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

    // //printf("store from previous: |%s|\n", store);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	char_read = read(fd, buf, BUFFER_SIZE);
	while (char_read > 0)
	{
        //printf("char_read: %d\n", char_read);
		buf[char_read] = '\0';
		if (store == NULL)
			store = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(store, buf);
			free(store);
			store = ft_strdup(temp);
			free(temp);
		}
        // //printf("store when exiting read_and_store: |%s|\n", store);
		if (ft_strchr(store, '\n'))
			break ;
		char_read = read(fd, buf, BUFFER_SIZE); // here
	}
	free (buf);
	if (store == NULL)
		return (NULL);
	if (store[0] == '\0')
	{
		free(store);
		return(NULL);
	}
	return (store);
}




//copy everything before '\n' into an array to print, and update store array
// static char	*ft_find_next_line(char *store)
// {
// 	char	*find_next_line;
// 	char	*tmp;
// 	int		break_index;
// 	int		store_len;

// 	if (store == NULL)
// 		return(NULL);
// 	store_len = ft_strlen(store);
// 	// tmp = NULL;
//     //printf("store len in fnl: %d\n", store_len);
// 	// //printf("tmp from previous: |%s|\n", tmp);
// 	// // ft_bzero(tmp, store_len);
// 	// //printf("initialised tmp: |%s|\n", tmp);


// 	// break index is to find index of char \n or last char in string
// 	break_index = 0;
// 	while (store[break_index] != '\0')
// 	{
// 		if (store[break_index] == '\n')
// 		{
// 			break_index++;
// 			break;
// 		}
// 		break_index++;
// 	}


		
// 	find_next_line = malloc(sizeof(char) * (break_index + 1)); // 1 for index to len, 1 for /0
// 	if (find_next_line == NULL)
// 		return (NULL);
// 	find_next_line[break_index] = '\0';
	
// 	//printf("breakindex:%i\n", break_index);
// 	if (store[break_index - 1] == '\n') // to find if there is a \n
// 	{
// 		// extract next line :
// 		ft_strlcpy(find_next_line, store, break_index + 1); // + 1 for index to len,
//         // //printf("1extracted line: |%s|\n", find_next_line);
		
		
// 		// update store :
// 		tmp = ft_substr(store, break_index, store_len - break_index);
// 		free(store);
// 		store = ft_strdup(tmp);
// 		// store[0] = '\0';
// 		free(tmp);
// 		tmp = NULL;
// 		// //printf("1updated store: |%s|\n", store);
// 		// //printf("in store mem: |%p|\n", store);

// 	}
// 	else
// 	{
// 		ft_strlcpy(find_next_line, store, store_len);
// 		free(store);
// 		store = NULL;
// 		// //printf("2extracted line: |%s|\n", find_next_line);
// 		// //printf("2updated store: |%s|\n", store);

// 	}
// 	free(find_next_line);
// 	return (store);
// }

int	ft_find_break_index(char *store, char c)
{
	int	break_index;
	
	break_index = 0;
	while ((store[break_index] != '\0') && (store[break_index] != c))
		break_index++;
	return(break_index);
}

static char	*ft_extract_next_line(char *store)
{
	char	*next_line;
	int		break_index;

	//printf("store_len in enl: %ld\n", ft_strlen(store));
	if (store == NULL)
		return (NULL);
	break_index = ft_find_break_index(store, '\n');
	if ((break_index == 0) && (store[0] != '\0') && (store[0] != '\n'))
		break_index = ft_strlen(store); // no new line but not empty
	//printf("break_index: %d\n", break_index);
	// while ((store[break_index] != '\0') && (store[break_index] != '\n'))
	// 	break_index++;
	//printf("break_index in enl: %d\n", break_index);
	next_line = malloc(sizeof(char) * (break_index + 2));
	if (next_line == NULL)
		return (NULL);
	ft_strlcpy(next_line, store, break_index + 2); // trying new line to replace below
	// if (store[break_index] == '\n')
	// 	ft_strlcpy(next_line, store, break_index + 2);
	// else
	// 	ft_strlcpy(next_line, store, break_index + 1);
	// //printf("next line in enl: |%s|\n", next_line);
	return (next_line);
}

static char	*ft_update_store(char *store)
{
	int	break_index;
	char	*tmp;
	int	store_len;

	store_len = ft_strlen(store);
	break_index = ft_find_break_index(store, '\n');
	//printf("store_len: %d\n", store_len);
	// while ((store[break_index] != '\0') && (store[break_index] != '\n'))
	// 	break_index++;
	if (store[break_index] == '\0')
	{
		free(store);
		return (NULL);
	}
	tmp = ft_substr(store, break_index + 1, store_len - break_index);
	free(store);
	store = ft_strdup(tmp);
	//printf("store in update: |%s|\n", store);
	free(tmp);
	tmp = NULL;
	return(store);	
}

// char	*get_next_line(int fd)
// {
// 	static char	*store;
// 	char		*next_line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	store = ft_read_and_store(fd, store);
// 	if (store == NULL)
// 		return (NULL);
// 	next_line = ft_find_next_line(store);
// 	return (next_line);
// }

char	*get_next_line(int fd)
{
	static char	*store;
	char		*next_line;

    //printf("*****************************\n");
    //printf("---ENTERING GNL FUNCTION WITH BUFFERSIZE = %d---\n", BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    //printf(">>>>ENTERING ft_read_and_store\n");
	store = ft_read_and_store(fd, store);
	if (store == NULL)
		return (NULL);
    //printf(">>>>ENTERING ft_extract_next_line\n");
	
	next_line = ft_extract_next_line(store);
	if (next_line == NULL)
		return (NULL);
	//printf(">>>>ENTERING update_store\n");	
	store = ft_update_store(store);

    //printf(">>>>EXIT GNL WITH LINE: |%s|\n", next_line);
    //printf(">>>>EXIT GNL WITH STORE: |%s|\n", store);
	// //printf(">>>>store mem: |%p|\n", store);
	//printf("*****************************\n");
	return (next_line);
}

// int	main(void)
// {
// 	int fd;
// 	char *s;

// 	fd = open("test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	//printf("line 1: |%s|\n", s);
// 	free(s);

// 	s = get_next_line(fd);
// 	//printf("line 2: |%s|\n", s);
// 	free(s);
	
//  	s = get_next_line(fd);
// 	//printf("line 3: |%s|\n", s);
// 	free(s);

// 	s = get_next_line(fd);
// 	// //printf("line 4: |%s|\n", s);
// 	free(s);
    
// // 	// s = get_next_line(fd);
// // 	// //printf("line 5: |%s|\n", s);
// // 	// free(s);

// // 	// s = get_next_line(fd);
// // 	// //printf("line 6: |%s|\n", s);
// // 	// free(s);

// 	close(fd);
// 	return(0);
// }