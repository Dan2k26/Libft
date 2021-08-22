/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:26:07 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/08/22 14:51:17 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_sep(const char *s, char c, char type)
{
	int	i;

	i = 0;
	if (type == 'p')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	else
	{
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (i);
}

static int	count_rows(const char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (s[0] && s[0] != c)
		cnt = 1;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			cnt++;
		i++;
	}
	return (cnt);
}

static void	ft_copy(char *ptr, const char *s, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
}

static char	**assing_str(char **str, const char *s, char c, int numrows)
{
	int	i;
	int	ncolumn;
	int	numchar;
	int	aux;

	i = 0;
	aux = count_sep(s, c, 'p');
	ncolumn = count_sep(&s[aux], c, 's');
	while (i < numrows)
	{
		str[i] = malloc((ncolumn + 1) * sizeof(char));
		ft_copy(str[i], &s[aux], ncolumn + 1);
		aux = aux + ncolumn;
		numchar = count_sep(&s[aux], c, 'p');
		aux = numchar + aux;
		ncolumn = count_sep(&s[aux], c, 's');
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		nrows;
	char	**str;

	if (s == NULL)
		return (NULL);
	nrows = count_rows(s, c);
	str = ft_calloc(sizeof(char *), (nrows + 1));
	if (str == NULL)
		return (NULL);
	str = assing_str(str, s, c, nrows);
	return (str);
}
