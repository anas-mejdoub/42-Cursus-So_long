/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:05:58 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/30 15:18:31 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_lose(t_var *var)
{
	void	*img;
	int		x;
	int		y;
	int		width;
	int		height;

	img = NULL;
	x = (get_map_width(var->map) * 32) / 2;
	y = (get_map_height(var->map) * 32) / 2;
	if (get_map_height(var->map) > 5)
	{
		y = y - (410 / 2);
		x = x - (565 / 2);
		img = mlx_xpm_file_to_image(var->env->mlx,
				"assetes/game_over/uchiha_win.xpm", &width, &height);
		mlx_put_image_to_window(var->env->mlx, var->env->win, img, x, y);
	}
	if (!img)
		red_cross(var);
	return (1);
}

int	closing_game(t_var *var)
{
	if (get_map_height(var->map) >= 5 && get_map_width(var->map) > 18)
	{
		mlx_clear_window(var->env->mlx, var->env->win);
		if (var->win == WIN)
		{
			close_win(var);
			return (1);
		}
		else
		{
			close_lose(var);
			return (1);
		}
	}
	return (red_cross(var));
}

void	game_start(t_var *var)
{
	int		width;
	int		height;
	void	*img;
	int		x;
	int		y;

	img = NULL;
	x = (get_map_width(var->map) * 32) / 2;
	y = (get_map_height(var->map) * 32) / 2;
	x = x - (1095 / 2);
	y = y - (679 / 2);
	img = mlx_xpm_file_to_image(var->env->mlx, "assetes/menu/menu_2.xpm",
			&width, &height);
	if (img == NULL)
		red_cross(var);
	if (get_map_height(var->map) >= 20 && get_map_width(var->map) > 33)
	{
		mlx_put_image_to_window(var->env->mlx, var->env->win, img, x, y);
		return ;
	}
	else
		var->game_state++;
	mlx_clear_window(var->env->mlx, var->env->win);
}

void	close_win_helper(t_var *var, int y, int x, char n)
{
	int		width;
	int		height;
	void	*img;

	if (n == '1')
	{
		y = y - (682 / 2);
		x = x - (1095 / 2);
		img = mlx_xpm_file_to_image(var->env->mlx, "assetes/win/naruto_win.xpm",
				&width, &height);
		if (!img)
			red_cross(var);
		mlx_put_image_to_window(var->env->mlx, var->env->win, img, x, y);
	}
	else if (n == '2')
	{
		y = y - (218 / 2);
		x = x - (415 / 2);
		img = mlx_xpm_file_to_image(var->env->mlx, "assetes/win/you_win.xpm",
				&width, &height);
		if (!img)
			red_cross(var);
		mlx_put_image_to_window(var->env->mlx, var->env->win, img, x, y);
	}
}

int	close_win(t_var *var)
{
	int	x;
	int	y;

	x = (get_map_width(var->map) * 32) / 2;
	y = (get_map_height(var->map) * 32) / 2;
	if (get_map_height(var->map) >= 15 && get_map_width(var->map) > 33)
	{
		close_win_helper(var, y, x, '1');
	}
	else
	{
		close_win_helper(var, y, x, '2');
	}
	return (1);
}
