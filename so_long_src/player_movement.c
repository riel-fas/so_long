/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:42:13 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/16 10:17:41 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void player_mov(void *param)
// {
// 	int x = 0;
// 	t_game *game = (t_game *) param;
// wasd
// 	// while (x < 30)
// 	// {
// 		// if (x = 10)
// 			//
// //
// //
// //
// //
// //
// //
// 	// }
// //


// 	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && check_wall(game->player_img->instances->x, )
// 	{
// 		if (check_wall(&game))
// 		{
// 			game->player_img->instances->y -= 3;
// 		}
// 		// game->player_next_y = game->player_img->instances->y - 3;
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_D) && check_wall(&game))
// 	{
// 		game->player_img->instances->x += 3;
// 		// game->player_next_x = game->player_img->instances->x + 3;
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
// 	{
// 		game->player_img->instances->x -= 3;
// 		// game->player_next_x = game->player_img->instances->x - 3;
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
// 	{
// 		game->player_img->instances->y += 3;
// 		// game->player_next_y = game->player_img->instances->y + 3;
// 	}
// // <>
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
// 	// {
// 		// game->player_img->instances->y -= 3;
// 		// game->player_next_x -= 6;
// 	// }
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		// game->player_img->instances->x += 3;
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		// game->player_img->instances->x -= 3;
// 	// if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 		// game->player_img->instances->y += 3;
// //
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->mlx);
// }

// bool	check_wall(t_game *game)
// {
// 	int		next_tile_x;
// 	int		next_tile_y;
// 	char	next_tile;

// 	next_tile_x = game->player_next_x / TILE_SIZE; //64 in this case
// 	next_tile_y = game->player_next_y / TILE_SIZE;

// 	if (next_tile_x > 0 || next_tile_x >= game->map_width || next_tile_y > 0 || next_tile_y >= game->map_height)
// 		return (false);

// 	next_tile = game->map[next_tile_x][next_tile_y];

// 	if (next_tile == '1')
// 		return (false);
// 	else
// 		return (true);
// }
//
//
//
//
//



void player_mov(void *param)
{
	t_game *game = (t_game *) param;


	int next_x;
	int next_y;



    // Debug: Print a message when the function is called
    printf("Keyboard function called\n");

    // WASD movement
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
        printf("W key pressed\n");
        next_y = game->player_img->instances->y -3;
		if (check_wall(game, game->player_img->instances->x, next_y))
			game->player_img->instances->y = next_y;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
        printf("D key pressed\n");
        next_x = game->player_img->instances->x + 3;
		if (check_wall(game, next_x, game->player_img->instances->y))
			game->player_img->instances->x = next_x;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
        printf("A key pressed\n");
        next_x = game->player_img->instances->x - 3;
		if (check_wall(game, next_x, game->player_img->instances->y))
			game->player_img->instances->x = next_x;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
        printf("S key pressed\n");
		next_y = game->player_img->instances->y + 3;
		if (check_wall(game, game->player_img->instances->x, next_y))
			next_y = game->player_img->instances->y;
    }

    // Arrow keys movement
    if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
        printf("UP key pressed\n");
        next_y = game->player_img->instances->y - 3;
		if (check_wall(game, game->player_img->instances->x, next_y))
			next_y = game->player_img->instances->y;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
        printf("RIGHT key pressed\n");
        next_x = game->player_img->instances->x + 3;
		if (check_wall(game, next_x, game->player_img->instances->y))
			next_x = game->player_img->instances->x;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
        printf("LEFT key pressed\n");
        next_x = game->player_img->instances->x - 3;
		if (check_wall(game, next_x, game->player_img->instances->y))
			next_x = game->player_img->instances->x;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
        printf("DOWN key pressed\n");
        next_y = game->player_img->instances->y + 3;
		if (check_wall(game, game->player_img->instances->x, next_y))
			next_y = game->player_img->instances->y;
    }

    // Close window on ESC
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) {
        printf("ESC key pressed\n");
        mlx_close_window(game->mlx);
    }
}
