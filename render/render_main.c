/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:29:49 by mel-adna          #+#    #+#             */
/*   Updated: 2025/08/04 16:22:56 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_scene(t_game *game)
{
	t_player	*p;
	float		fraction;
	float		ray_angle;
	int			col;

	p = &game->player;
	fraction = PI / 3 / WIDTH;
	ray_angle = p->angle - PI / 6;
	col = 0;
	clear_image(game);
	while (col < WIDTH)
	{
		draw_textured_line(p, game, ray_angle, col);
		ray_angle += fraction;
		col++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

static void	update_angle(t_player *p, int delta_x)
{
	p->angle += delta_x * 0.002;
	if (p->angle < 0)
		p->angle += 2 * PI;
	else if (p->angle > 2 * PI)
		p->angle -= 2 * PI;
}

void	update_player_angle_and_position(t_game *game)
{
	static int	last_mouse_x = -1;
	int			mouse_x;
	int			mouse_y;
	int			delta_x;

	if (game->window_focused)
	{
		mlx_mouse_get_pos(game->win, &mouse_x, &mouse_y);
		if (mouse_x >= 0 && mouse_x < WIDTH && mouse_y >= 0 && mouse_y < HEIGHT)
		{
			if (last_mouse_x == -1)
				last_mouse_x = mouse_x;
			delta_x = mouse_x - last_mouse_x;
			last_mouse_x = mouse_x;
			if (delta_x)
				update_angle(&game->player, delta_x);
		}
		else
			last_mouse_x = -1;
	}
	move_player(&game->player, game);
}

int	draw_loop(t_game *game)
{
	update_player_angle_and_position(game);
	render_scene(game);
	return (0);
}
