/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:33:17 by mel-adna          #+#    #+#             */
/*   Updated: 2025/08/04 16:31:11 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int kc, t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (kc == ESC)
		return (exit_game(game));
	if (kc == W)
		p->key_up = true;
	if (kc == S)
		p->key_down = true;
	if (kc == A)
		p->key_left = true;
	if (kc == D)
		p->key_right = true;
	if (kc == LEFT)
		p->left_rotate = true;
	if (kc == RIGHT)
		p->right_rotate = true;
	return (0);
}

int	key_release(int kc, t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (kc == W)
		p->key_up = false;
	if (kc == S)
		p->key_down = false;
	if (kc == A)
		p->key_left = false;
	if (kc == D)
		p->key_right = false;
	if (kc == LEFT)
		p->left_rotate = false;
	if (kc == RIGHT)
		p->right_rotate = false;
	return (0);
}

bool	is_wall_collision(float x, float y, t_game *g)
{
	int	mx;
	int	my;

	mx = (int)(x / BLOCK);
	my = (int)(y / BLOCK);
	return (mx < 0 || my < 0 || g->map[my][mx] == '1');
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	last_x = -1;
	int			delta_x;

	if (last_x == -1)
		last_x = x;
	delta_x = x - last_x;
	last_x = x;
	if (delta_x != 0)
	{
		game->player.angle += delta_x * 0.002;
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
		else if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
	}
	(void)y;
	return (0);
}
