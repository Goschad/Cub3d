/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 05:49:48 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/28 04:36:24 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// check_slash2 //

static void	check_slash2(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '.' && line[i + 1] == '/')
			check->point++;
		i++;
	}
}

// check_slash //

void	check_slash(char **map, t_check *check)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == 'S' || map[i][0] == 'N'
				|| map[i][0] == 'W' || map[i][0] == 'E')
			check_slash2((map[i]), check);
		i++;
	}
}

// strjoin qui marche

char	*ft_strjoin_qui_marche(char *str1, char *str2)
{
	char	*str;
	int		i;

	str = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (str && str1[++i])
		str[i] = str1[i];
	i = -1;
	while (str2 && str2[++i])
		str[i + ft_strlen(str1)] = str2[i];
	str[i + ft_strlen(str1)] = '\0';
	return (str);
}

// remove_space //

char	*remove_space(char *line)
{
	char	**buff;
	char	*buff2;
	char	*new_line;

	buff = ft_split(line, ' ');
	buff2 = ft_strjoin_qui_marche(buff[0], " ");
	new_line = ft_strjoin_qui_marche(buff2, buff[1]);
	free_tab(buff);
	free(buff2);
	return (new_line);
}

// init_check //

void	init_check(t_check *check)
{
	check->no = 0;
	check->no2 = 0;
	check->so = 0;
	check->we = 0;
	check->ea = 0;
	check->other = 0;
	check->point = 0;
}
