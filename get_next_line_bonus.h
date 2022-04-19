/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:02:16 by lsinke        #+#    #+#                 */
/*   Updated: 2022/04/19 18:02:16 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>

typedef struct s_buf_list
{
	int					fd;
	char				*leftover;
	struct s_buf_list	*next;
}	t_buf_list;

char		*get_next_line(int fd);

/**
 * Null safe version of strlen. Returns 0 if the string is NULL
 */
size_t		ft_strlen(const char *s);
/**
 * Finds a newline character in the string, and returns a pointer to it
 * returns NULL if no newline was found
 */
char		*find_newline(char *str);
/**
 * Find a list object with the correct fd in the list
 * create one if not found
 */
t_buf_list	*find_or_create_list(t_buf_list **list, int fd);
/**
 * Removes a list item from the list, setting list to NULL if item was first
 */
void		remove_list_item(t_buf_list **list, t_buf_list *item);

#endif