/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:48:21 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/14 15:48:22 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char to_find)
{
	int i;

	if (to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}

int		ft_wordcounter(char *str, char *sep)
{
	int		i;
	int		wcount;
	int		state;

	i = 0;
	wcount = 0;
	state = 0;
	while (str[i])
	{
		if (ft_strstr(sep, str[i]) != NULL)
		{
			state = 0;
		}
		else if (state == 0)
		{
			state = 1;
			wcount++;
		}
		i++;
	}
	return (wcount);
}

char	*ft_strcpy(int ccount, char *str, int i)
{
	char	*res;
	int		k;

	res = (char*)malloc(sizeof(char) * (ccount + 1));
	k = 0;
	while (k < ccount)
	{
		res[k] = str[i - ccount + k];
		k++;
	}
	res[k] = '\0';
	ccount = 0;
	return (res);
}

char	**ft_word_extractor(char *str, char **strtab, char *charset, int v[5])
{
	while (str[v[4]])
		v[4]++;
	while (v[0] <= v[4])
	{
		if (ft_strstr(charset, str[v[0]]) != NULL)
		{
			if (v[3] == 1)
			{
				strtab[v[1]] = ft_strcpy(v[2], str, v[0]);
				v[1]++;
				v[2] = 0;
				v[3] = 0;
			}
		}
		else if (v[3] == 0)
		{
			v[3] = 1;
			v[2]++;
		}
		else
			v[2]++;
		v[0]++;
	}
	strtab[ft_wordcounter(str, charset)] = NULL;
	return (strtab);
}

char	**ft_split(char *str, char *charset)
{
	char	**strtab;
	int		wcount;
	int		v[5];

	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[4] = 0;
	wcount = ft_wordcounter(str, charset);
	strtab = (char**)malloc(sizeof(*strtab) * (wcount + 1));
	strtab = ft_word_extractor(str, strtab, charset, v);
	return (strtab);
}
