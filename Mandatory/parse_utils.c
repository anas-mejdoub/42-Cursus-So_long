/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:57:29 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 12:58:22 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	remove_nl(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		map[i] = ft_substr2(map[i], 0, ft_strlen(map[i]) - 1, 'f');
		i++;
	}
}

int	check_wall_helper(int i, int j, int last, char **map)
{
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (map[i] && map[i][0])
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i] && map[i][last])
	{
		if (map[i][last] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_execp(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("C10PE", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
