#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "minirt.h"
#include <fcntl.h>
#include <stdlib.h>

t_list *getlines(int fd)
{
	t_list* head;
	t_list* current;
	char 	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return 0;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = 0;
	head = ft_lstnew(line);
	current = head;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		current->next = malloc(sizeof(t_list));
		current = current->next;
		current->content = line;
		current->next = 0;
	}
	close(fd);
	return (head);
}

int checkiffloat(char *str, float range, float lower, float upper)
{
	int	f;
	int	i;

	f = 0;
	i = -1;
	if (!ft_isdigit(str[ft_strlen(str) - 1]))
		return (0);
	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			continue;	
		else if (str[i] != '.' && !ft_isdigit(str[i]))
			return (0);
		else if (str[i] == '.' && f == 0)
			f = 1;
		else if (f && str[i] == '.')
			return (0);
	}
	if (range)
	{
		if (ft_atof(str) <= upper && ft_atof(str) >= lower)
			return (1);
		return (0);
	}
	return (1);
}


t_token	*checka(char **tokens)
{
	int		i;
	char	**aux;
	t_token	*ret;

	i = 0;

	while(tokens[i])
		i++;
	if (i != 3 || !checkiffloat(tokens[1], 1, 0.0f, 1.0f))
		return (0);
	aux = ft_split(tokens[2], ',');
	i = 0;
	while(aux[i] && checkifint(aux[i], 1, 0, 255))
		i++;
	ret = 0;
	if (i == 3)
	{
		ret = ft_calloc(1, sizeof(t_token));
		ret->type = "A";
		ret->a_rgb[0] = ft_atoi(aux[0]);
		ret->a_rgb[1] = ft_atoi(aux[1]);
		ret->a_rgb[2] = ft_atoi(aux[2]);
		ret->a_lighting = ft_atof(tokens[1]);
	}
	freejoin(aux);
	return (ret);
}
t_token	*checkc(char **tokens)
{
	int		i[2];
	char	**aux[2];
	t_token	*ret;

	i[0] = 0;
	while(tokens[i[0]])
		i[0]++;
	if (i[0] != 4 || !checkifint(tokens[3], 1, 0, 180))
		return (0);
	aux[0] = ft_split(tokens[1], ',');
	aux[1] = ft_split(tokens[2], ',');
	ft_memset(i, 0, sizeof(i));
	while(aux[0][i[0]] && checkiffloat(aux[0][i[0]], 0, 0, 0))
		i[0]++;
	while(aux[1][i[1]] && checkiffloat(aux[1][i[1]], 1, -1, 1))
		i[1]++;
	ret = 0;
	if (i[0] == 3 && i[1] == 3)
	{
		ret = ft_calloc(1, sizeof(t_token));
		ret->type = "C";
		ret->c_xyz[0] = ft_atof(aux[0][0]);
		ret->c_xyz[1] = ft_atof(aux[0][1]);
		ret->c_xyz[2] = ft_atof(aux[0][2]);
		ret->c_orientation[0] = ft_atof(aux[1][2]);
		ret->c_orientation[1] = ft_atof(aux[1][2]);
		ret->c_orientation[2] = ft_atof(aux[1][2]);
		ret->c_fov = ft_atoi(tokens[3]);
	}
	freejoin(aux[0]);
	freejoin(aux[1]);
	return (ret);
}

t_token	*checkl(char **tokens)
{
	int		i[2];
	char	**aux[2];
	t_token	*ret;

	i[0] = 0;
	while(tokens[i[0]])
		i[0]++;
	if (i[0] != 4 || !checkiffloat(tokens[2], 1, 0.0f, 1.0f))
		return (0);
	aux[0] = ft_split(tokens[1], ',');
	ft_memset(i, 0, sizeof(i));
	while(aux[0][i[0]] && checkiffloat(aux[0][i[0]], 0, 0, 0))
		i[0]++;
	ret = 0;
	if (i[0] == 3)
	{
		ret = ft_calloc(1, sizeof(t_token));
		ret->type = "L";
		ret->l_xyz[0] = ft_atof(aux[0][0]);
		ret->l_xyz[1] = ft_atof(aux[0][1]);
		ret->l_xyz[2] = ft_atof(aux[0][2]);
		ret->l_brightness = ft_atof(tokens[2]);
	}
	freejoin(aux[0]);
	return (ret);
}
t_token	*checksp(char **tokens)
{
	int		i[2];
	char	**aux[2];
	t_token	*ret;

	i[0] = 0;
	while(tokens[i[0]])
		i[0]++;
	if (i[0] != 4 || !checkiffloat(tokens[2], 0, 0, 0))
		return (0);
	aux[0] = ft_split(tokens[1], ',');
	aux[1] = ft_split(tokens[3], ',');
	ft_memset(i, 0, sizeof(i));
	while(aux[0][i[0]] && checkiffloat(aux[0][i[0]], 0, 0, 0))
		i[0]++;
	while(aux[1][i[1]] && checkifint(aux[1][i[1]], 1, 0, 255))
		i[1]++;
	ret = 0;
	if (i[0] == 3 && i[1] == 3)
	{
		ret = ft_calloc(1, sizeof(t_token));
		ret->type = "sp";
		ret->sp_xyz[0] = ft_atof(aux[0][0]);
		ret->sp_xyz[1] = ft_atof(aux[0][1]);
		ret->sp_xyz[2] = ft_atof(aux[0][2]);
		ret->sp_diameter = ft_atof(tokens[2]);
		ret->sp_rgb[0] = ft_atoi(aux[1][0]);
		ret->sp_rgb[1] = ft_atoi(aux[1][1]);
		ret->sp_rgb[2] = ft_atoi(aux[1][2]);
	}
	freejoin(aux[0]);
	freejoin(aux[1]);
	return (ret);
}

t_token	*checkpl(char **tokens)
{
	int		i[3];
	char	**aux[3];
	t_token	*ret;

	i[0] = 0;
	while(tokens[i[0]])
		i[0]++;
	if (i[0] != 4)
		return (0);
	aux[0] = ft_split(tokens[1], ',');
	aux[1] = ft_split(tokens[2], ',');
	aux[2] = ft_split(tokens[3], ',');
	ft_memset(i, 0, sizeof(i));
	while (aux[0][i[0]] && checkiffloat(aux[0][i[0]], 0, 0, 0))
		i[0]++;
	while (aux[1][i[1]] && checkiffloat(aux[1][i[1]], 1, -1.0f, 1.0f))
		i[1]++;
	while (aux[2][i[2]] && checkifint(aux[2][i[2]], 1, 0, 255))
		i[2]++;
	ret = 0;
	if (i[0] == 3 && i[1] == 3 && i[2] == 3)
	{
		ret = ft_calloc(1, sizeof(t_token));
		ret->type = "pl";
		ret->pl_xyz[0] = ft_atof(aux[0][0]);
		ret->pl_xyz[1] = ft_atof(aux[0][1]);
		ret->pl_xyz[2] = ft_atof(aux[0][2]);
		ret->pl_vector[0] = ft_atof(aux[1][0]);
		ret->pl_vector[1] = ft_atof(aux[1][1]);
		ret->pl_vector[2] = ft_atof(aux[1][2]);
		ret->pl_rgb[0] = ft_atoi(aux[2][0]);
		ret->pl_rgb[1] = ft_atoi(aux[2][1]);
		ret->pl_rgb[2] = ft_atoi(aux[2][2]);
	}
	freejoin(aux[0]);
	freejoin(aux[1]);
	freejoin(aux[2]);
	return (ret);
}

t_token	*checkcy(char **tokens)
{
	int		i[3];
	char	**aux[3];
	t_token	*ret;

	i[0] = 0;
	while(tokens[i[0]])
		i[0]++;
	if (i[0] != 6 || (!checkiffloat(tokens[3], 0, 0, 0) && !checkiffloat(tokens[4], 0, 0, 0)))
		return (0);
	aux[0] = ft_split(tokens[1], ',');
	aux[1] = ft_split(tokens[2], ',');
	aux[2] = ft_split(tokens[5], ',');
	ft_memset(i, 0, sizeof(i));
	while (aux[0][i[0]] && checkiffloat(aux[0][i[0]], 0, 0, 0))
		i[0]++;
	while(aux[1][i[1]] && checkiffloat(aux[1][i[1]], 1, -1.0f, 1.0f))
		i[1]++;
	while(aux[2][i[2]] && checkifint(aux[2][i[2]], 1, 0, 255))
		i[2]++;
	ret = 0;
	if (i[0] == 3 && i[1] == 3 && i[2] == 3)
	{
		ret = ft_calloc(1, sizeof(t_token));
		ret->type = "cy";
		ret->cy_xyz[0] = ft_atof(aux[0][0]);
		ret->cy_xyz[1] = ft_atof(aux[0][1]);
		ret->cy_xyz[2] = ft_atof(aux[0][2]);
		ret->cy_vector[0] = ft_atof(aux[1][0]);
		ret->cy_vector[1] = ft_atof(aux[1][1]);
		ret->cy_vector[2] = ft_atof(aux[1][2]);
		ret->cy_diameter = ft_atoi(tokens[3]);
		ret->cy_height = ft_atoi(tokens[4]);
		ret->sp_rgb[0] = ft_atoi(aux[2][0]);
		ret->sp_rgb[1] = ft_atoi(aux[2][1]);
		ret->sp_rgb[2] = ft_atoi(aux[2][2]);
	}
	freejoin(aux[0]);
	freejoin(aux[1]);
	freejoin(aux[2]);
	return (ret);
}

void	addfinaltokens(t_token *t, t_list **head)
{
	t_list	*tmp;

	if (*head == NULL)
		*head = ft_lstnew(t);
	else
	{
		tmp = *head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_list));
		tmp = tmp->next;
		tmp->content = t;
		tmp->next = 0;
	}
}

t_list	*verifytokens(t_list *list)
{
	char	**tokens;
	t_token	*token;
	t_list	*finaltokens;
	t_list	*listaux;

	finaltokens = 0;
	listaux = list;
	while(listaux)
	{
		tokens = ft_split(listaux->content, ' ');
		token = 0;
		if (!ft_strcmp(tokens[0], "A"))
			token = checka(tokens);
		else if (!ft_strcmp(tokens[0], "C"))
			token = checkc(tokens);
		else if (!ft_strcmp(tokens[0], "L"))
			token = checkl(tokens);
		else if (!ft_strcmp(tokens[0], "sp"))
			token = checksp(tokens);
		else if (!ft_strcmp(tokens[0], "pl"))
			token = checkpl(tokens);
		else if (!ft_strcmp(tokens[0], "cy"))
			token = checkcy(tokens);
		freejoin(tokens);
		if (token)
			addfinaltokens(token, &finaltokens);
		else
		{
			ft_lstclear(&finaltokens, free);
			ft_lstclear(&list, free);
			return (finaltokens);
		}
		listaux = listaux->next;
	}
	ft_lstclear(&list, free);
	return (finaltokens);
}
