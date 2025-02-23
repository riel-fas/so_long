/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:19:52 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/23 06:18:43 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
t_game game;

// Initialize MLX and create a window
game.mlx = mlx_init(800, 600, "so_long", true);
if (!game.mlx)
    return (EXIT_FAILURE);

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

// Register the key hook
mlx_key_hook(game.mlx, keyboard, &game);

// Draw the initial map
// draw_map(&game);

// Start the MLX event loop
mlx_loop(game.mlx);

// Clean up and exit
mlx_terminate(game.mlx);
return (EXIT_SUCCESS);
}
