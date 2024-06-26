/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:37:53 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/29 15:12:29 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_map(t_coins_var *variable)
{
	intialcounter(variable->var);
	if (check_winner(variable->var->map) == 1)
	{
		ft_printf("congrats You win !\ngame closing\n");
		destroy_images(variable->var->env, 1);
		free2d(variable->var->map);
		exit(0);
	}
	render_helper(*variable->var, 0, 0, (t_point){0, 0});
	if (variable->var->map[variable->var->p_pos->y][variable->var->p_pos->x]
	== 'C')
		variable->var->map[variable->var->p_pos->y][variable->var->p_pos->x]
			= '0';
	mlx_put_image_to_window(variable->var->env->mlx, variable->var->env->win,
		variable->var->env->img.player_r, variable->var->p_pos->x * 32,
		variable->var->p_pos->y * 32);
	return (1);
}

void	render_helper(t_var var, int i, int y, t_point point)
{
	while (var.map[i])
	{
		point.x = 0;
		y = 0;
		while (var.map[i][y])
		{
			if (var.map[i][y] == '1')
				build_outer_wall(var.map, (t_point){i, y}, (t_point){point.y,
					point.x}, var.env);
			if (ft_strrchr("0XPEC", var.map[i][y]))
				mlx_put_image_to_window(var.env->mlx, var.env->win,
					var.env->img.floor, point.x, point.y);
			if (var.map[i][y] == 'E')
				render_exit(&var, &point);
			if (var.map[i][y] == 'X')
				mlx_put_image_to_window(var.env->mlx, var.env->win,
					var.env->img.enemy_right, point.x, point.y);
			point.x += 32;
			y++;
		}
		point.y += 32;
		i++;
	}
}

void	render_exit(t_var *var, t_point *point)
{
	if (check_winner(var->map) == 2)
		var->env->img.door = var->env->img.opened_door;
	mlx_put_image_to_window(var->env->mlx, var->env->win, var->env->img.door,
		point->x, point->y);
}

void	build_outer_wall(char **map, t_point p, t_point p2, t_env *env)
{
	if (p.y == get_map_height(map) - 1 && (p.x != 0 && p.x != get_map_width(map)
			- 1))
		mlx_put_image_to_window(env->mlx, env->win, env->img.upper_counter,
			p2.x, p2.y);
	else if (p.y == 0 || p.x == 0 || p.x == get_map_width(map) - 1
		|| p.y == get_map_height(map) - 1)
		mlx_put_image_to_window(env->mlx, env->win, env->img.floor_counter,
			p2.x, p2.y);
	else
		mlx_put_image_to_window(env->mlx, env->win, env->img.inner_wall, p2.x,
			p2.y);
}

int	check_assets(t_env *env)
{
	if (!env->img.outer_wall || !env->img.opened_door || !env->img.inner_wall
		|| !env->img.floor || !env->img.door || !env->img.player_r
		|| !env->img.player_d || !env->img.player_u || !env->img.player_l)
		return (0);
	return (1);
}
