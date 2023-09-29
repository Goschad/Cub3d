/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:59:56 by mbouaza           #+#    #+#             */
/*   Updated: 2023/07/13 16:22:17 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**hide_map(char **map)
{
	char	**hide;
	int		i;

	if (!map)
		return (NULL);
	i = 0;
	hide = malloc(sizeof(char *) * (ft_strrlen(map) + 1 + 2));
	while (map[i])
	{
		hide[i] = ft_strjoin2(map[i], "0000000000000");
		i++;
	}
	hide[i++] = ft_strdup("0000000000000");
	hide[i++] = ft_strdup("0000000000000");
	hide[i] = NULL;
	return (hide);
}

// verif_empty //

int	verif_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}
