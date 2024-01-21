/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:20:16 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/08 19:01:48 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_n_words(const char *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			n++;
		if (s[i] == c && i != (int)ft_strlen(s) - 1)
		{
			if (s[i + 1] != c)
				n++;
		}
		i++;
	}
	return (n);
}

static void	ft_str_create(const char *s, char **str, char c)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	j = 0;
	len = 0;
	while (s[++i])
	{
		if (s[i] != c)
			len++;
		else
		{
			if (len)
			{
				str[j++] = (char *)malloc(sizeof(char) * (len + 1));
				len = 0;
			}
		}
	}
	if (len)
		str[j] = (char *)malloc(sizeof(char) * (len + 1));
}

static void	ft_str_allocate(const char *s, char **str, char c, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (n > 0)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		str[j][k] = '\0';
		k = 0;
		j++;
		n--;
	}
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**str;

	if (!s)
		return (NULL);
	n = ft_n_words(s, c);
	str = malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (NULL);
	ft_str_create(s, str, c);
	ft_str_allocate(s, str, c, n);
	str[n] = 0;
	return (str);
}

/* int main(int argc, char *argv[]) */
/* { */
/*  	char *s = "                  olol"; */
/* 	char **p=ft_split(argv[1], argv[2][0]); */
/* 	for (int i=0; p[i] ; i++) */
/* 		printf("%s\n",p[i]); */
/* 	return 0; */
/* } */
	/* while (s[++i]) */
	/* { */
	/* 	if (s[i] != c) */
	/* 	{ */
	/* 		f[k][j] = s[i]; */
	/* 		j++; */
	/* 	} */
	/* 	else if (j) */
	/* 	{ */
	/* 		f[k++][j] = '\0'; */
	/* 		j = 0; */
	/* 	} */
	/* } */
