/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 04:51:22 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/28 05:28:47 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// ft_error //

void	ft_error(char *str)
{
	write(2, "Error\n", 6);
	if (str)
		write(2, str, ft_strlen(str));
}

// free_tab //

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
