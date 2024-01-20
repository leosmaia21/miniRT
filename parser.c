#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "minirt.h"
#include <fcntl.h>
#include <iterator>
#include <stdlib.h>

t_list *getlines(char * filename)
{
	int		fd;
	t_list* head;
	t_list* current;
	char 	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return 0;
	head = malloc(sizeof(t_list));
	head->content = line;
	head->next = 0;
	current = head;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		current->next = malloc(sizeof(t_list));
		current = current->next;
		current->content = line;
		current->next = 0;
	}
	close(fd);
	return (head);
}

int checkiffloat(char *str)
{
	int	f;

	f = 0;
	while (*str)
	{
		if (*str != '.' && !ft_isdigit(*str))
			return (0);
		else if (*str == '.' && f == 0)
			f = 1;
		else 
			return (0);
		str++;
	}
	return (1);
}

int checkifint(char *str)
{
	while(*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
t_a	*checka(char **tokens)
{
	int		i;
	char	**aux;
	t_a		*ret;

	i = 0;
	while(tokens[i])
		i++;
	if (i != 3 || !checkiffloat(tokens[1]))
		return (0);
	aux = ft_split(tokens[2], ',');
	i = -1;
	while(aux[++i])
		if (!checkifint(aux[i]))
			break;
	ret = 0;
	if (i == 3)
	{
		ret = malloc(sizeof(t_a));
		ret->type = "A";
		ret->rgb[0] = ft_atoi(aux[0]);
		ret->rgb[1] = ft_atoi(aux[1]);
		ret->rgb[2] = ft_atoi(aux[2]);
		ret->lighting = ft_atof(tokens[1]);
	}
	freejoin(aux);
	return (ret);
}

int	verifytokens(t_list *list)
{
	char	**tokens;

	while(list)
	{
		tokens = ft_split(list->content, ' ');
		if (!ft_strcmp(tokens[0], "A"))
			checka(tokens);
		else if (!ft_strcmp(tokens[0], "C"))
			checka();
		else if (!ft_strcmp(tokens[0], "L"))
			checka();
		else if (!ft_strcmp(tokens[0], "sp"))
			checka();
		else if (!ft_strcmp(tokens[0], "pl"))
			checka();
		else if (!ft_strcmp(tokens[0], "cy"))
			checka();
		else
			return (1);
	}
}
