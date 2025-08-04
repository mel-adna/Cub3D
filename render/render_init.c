/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <mel-adna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:15:29 by mel-adna          #+#    #+#             */
/*   Updated: 2025/08/04 15:51:26 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game_render(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	game->window_focused = true;
	load_textures(game);
}

void	init_player(t_player *p)
{
	p->x = WIDTH / 2;
	p->y = HEIGHT / 2;
	p->angle = PI / 2;
	p->key_up = false;
	p->key_down = false;
	p->key_left = false;
	p->key_right = false;
	p->left_rotate = false;
	p->right_rotate = false;
}

void	clear_image(t_game *game)
{
	int	image_size;

	image_size = HEIGHT * game->size_line;
	ft_memset(game->data, 0, image_size);
}

int	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_loop_hook(game->mlx, draw_loop, game);
	mlx_hook(game->win, 9, (1L << 21), on_focus_in, game);
	mlx_hook(game->win, 10, (1L << 22), on_focus_out, game);
	return (0);
}
