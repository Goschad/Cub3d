/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:13:50 by mbouaza           #+#    #+#             */
/*   Updated: 2023/06/28 04:31:12 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// delete_newline //

// delete new line in the end of an char * //

static	char	*delete_newline(char *line)
{
	int		i;
	char	*newline;

	i = 0;
	newline = NULL;
	if (!line)
		return (free(line), newline);
	while (line[i] && line[i] != '\n')
		i++;
	newline = malloc(sizeof(char) * i + 1);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		newline[i] = line[i];
		i++;
	}
	newline[i] = '\0';
	free(line);
	return (newline);
}

// pix_ft //

int32_t	pix_ft(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// delete_all_newline //

void	delete_all_newline(t_cube *cub)
{
	cub->t->t_no = delete_newline(cub->t->t_no);
	cub->t->t_so = delete_newline(cub->t->t_so);
	cub->t->t_we = delete_newline(cub->t->t_we);
	cub->t->t_ea = delete_newline(cub->t->t_ea);
}

// freel //

void	freel(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
