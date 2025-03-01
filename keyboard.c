/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:42:13 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/01 04:51:04 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void keyboard(void *param)
{
	t_game *game = (t_game *) param;
//wasd
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->player_img->instances[0].y -= 3;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->player_img->instances[0].x += 3;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->player_img->instances[0].x -= 3;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->player_img->instances[0].y += 3;
// <>
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->player_img->instances[0].y -= 3;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player_img->instances[0].x += 3;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player_img->instances[0].x -= 3;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->player_img->instances[0].y += 3;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
