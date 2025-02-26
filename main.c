/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:19:52 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/26 12:52:12 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void work(void *param) {
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

int main()
{
t_game game;

// Initialize MLX and create a window
game.mlx = mlx_init(800, 600, "so_long", true);
if (!game.mlx)
    return (EXIT_FAILURE);
game.player_img = mlx_new_image(game.mlx, 100, 100);
for (int i = 0; i < 100; i++)
	for (int k = 0; k < 100;k++)
		mlx_put_pixel(game.player_img, k,i, 102);
mlx_image_to_window(game.mlx, game.player_img, 400, 300);

// Register the key hook
// mlx_key_hook(game.mlx, keyboard, &game);
mlx_loop_hook(game.mlx, work, &game);
// Draw the initial map
// draw_map(&game);

// Start the MLX event loop
mlx_loop(game.mlx);

// Clean up and exit
mlx_terminate(game.mlx);
return (EXIT_SUCCESS);
}





// // Initialize the game state (hardcoded for now)
// game.map = (char *[]) {
//     "11111",
//     "10P01",
//     "1C0E1",
//     "11111",
//     NULL
// };
// game.map_width = 5;
// game.map_height = 4;
// game.player_x = 2; // Initial player position
// game.player_y = 1;
// game.moves = 0;    // Initialize move counter
