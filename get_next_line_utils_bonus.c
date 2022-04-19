/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:02:17 by lsinke        #+#    #+#                 */
/*   Updated: 2022/04/19 18:02:17 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != '\0')
		++l;
	return (l);
}

char	*find_newline(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (str);
			++str;
		}
	}
	return (NULL);
}

static t_buf_list	*create_list(int fd)
{
	t_buf_list	*obj;

	obj = malloc(1 * sizeof(t_buf_list));
	if (!obj)
		return (NULL);
	obj->fd = fd;
	obj->leftover = NULL;
	obj->next = NULL;
	return (obj);
}

t_buf_list	*find_or_create_list(t_buf_list **list, int fd)
{
	t_buf_list	*cur;

	if (*list == NULL)
	{
		*list = create_list(fd);
		return (*list);
	}
	cur = *list;
	while (cur->fd != fd)
	{
		if (cur->next == NULL)
			cur->next = create_list(fd);
		cur = cur->next;
		if (cur == NULL)
			return (NULL);
	}
	return (cur);
}

void	remove_list_item(t_buf_list **list, t_buf_list *item)
{
	t_buf_list	*cur;

	if (*list == item)
	{
		*list = item->next;
	}
	else
	{
		cur = *list;
		while (cur->next != item)
			cur = cur->next;
		cur->next = item->next;
	}
	free(item);
}
