/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:56:57 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/13 21:27:00 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../Libft/libft.h"
#include <mlx.h>
char **map_parsing();
void	free2d(char **str);
int get_map_height(char **map);
int get_map_width(char **map);
int floodfill(char **map);
int is_filled(char **map);
typedef struct	s_point
{
	int			y;
	int			x;
}				t_point;

#endif