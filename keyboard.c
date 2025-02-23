/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:42:13 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/23 06:19:38 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	keyboard(mlx_key_data_t keydata, void *param)
// {
// 	t_game *game;

// 	game = param;

// 	//when pressing ESC the window closes
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(game->mlx);

// 	//handle w a s d
// 	if (keydata.action == MLX_PRESS)
// 	{
// 		int new_x = game->player_x;
// 		int new_y = game->player_y;
// 		//updating player position while moving on the map
// 		//(x, y) right / up + 1 || left/down -1
// 		// W A S D
// 		if (keydata.key == MLX_KEY_W)
// 			new_y -= 1;
// 		else if (keydata.key == MLX_KEY_S)
// 			new_y += 1;
// 		else if (keydata.key == MLX_KEY_A)
// 			new_x -= 1;
// 		else if (keydata.key == MLX_KEY_D)
// 			new_x += 1;
// 		//up down left right
// 		else if (keydata.key == MLX_KEY_UP)
// 			new_y -= 1;
// 		else if (keydata.key == MLX_KEY_DOWN)
// 			new_y += 1;
// 		else if (keydata.key == MLX_KEY_LEFT)
// 			new_x -= 1;
// 		else if (keydata.key == MLX_KEY_RIGHT)
// 			new_x += 1;


// 	        // Check if the new position is valid (not a wall or outside the map)
//         if (new_x >= 0 && new_x < game->map_width &&
//             new_y >= 0 && new_y < game->map_height &&
//             game->map[new_y][new_x] != '1')
//         {
//             // Update the player's position
//             game->player_x = new_x;
//             game->player_y = new_y;

//             // Increment the move counter
//             game->moves++;
//             printf("Moves: %d\n", game->moves);

//             // Redraw the map to reflect the player's new position
//             // draw_map(game);

// 		}

// 	}
// }



void keyboard(mlx_key_data_t keydata, void *param)
{
    t_game *game = param;

    // Close the window if the Escape key is pressed
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);

    // Handle movement keys
    if (keydata.action == MLX_PRESS)
    {
        int new_x = game->player_x;
        int new_y = game->player_y;

        // Update the player's position based on the key pressed
        if (keydata.key == MLX_KEY_W) // Move up
            new_y -= 1;
        else if (keydata.key == MLX_KEY_S) // Move down
            new_y += 1;
        else if (keydata.key == MLX_KEY_A) // Move left
            new_x -= 1;
        else if (keydata.key == MLX_KEY_D) // Move right
            new_x += 1;

        // Check if the new position is valid (not a wall or outside the map)
        if (new_x >= 0 && new_x < game->map_width &&
            new_y >= 0 && new_y < game->map_height &&
            game->map[new_y][new_x] != '1')
        {
            // Update the player's position
            game->player_x = new_x;
            game->player_y = new_y;

            // Increment the move counter
            game->moves++;
            printf("Moves: %d\n", game->moves);

            // Redraw the map to reflect the player's new position
            // draw_map(game);
        }
    }
}


// void draw_map(t_game *game)
// {
//     for (int y = 0; y < game->map_height; y++)
//     {
//         for (int x = 0; x < game->map_width; x++)
//         {
//             uint32_t color = 0x000000FF; // Default: Black
//             if (game->map[y][x] == '1')
//                 color = 0xFFFFFFFF; // White for walls
//             else if (x == game->player_x && y == game->player_y)
//                 color = 0xFF0000FF; // Red for player
//             else if (game->map[y][x] == 'C')
//                 color = 0x00FF00FF; // Green for collectibles
//             else if (game->map[y][x] == 'E')
//                 color = 0x0000FFFF; // Blue for exit

//             // Draw a rectangle for each tile
//             for (int i = 0; i < TILE_SIZE; i++)
//                 for (int j = 0; j < TILE_SIZE; j++)
//                     // mlx_put_pixel(game->mlx, x * TILE_SIZE + i, y * TILE_SIZE + j, color);
//         }
//     }
// }




// function key_hook(key_data, game_struct):
//     // Close the window if the Escape key is pressed
//     if key_data.key == ESCAPE and key_data.action == PRESS:
//         close_window(game_struct.mlx_instance)

//     // Handle movement keys
//     if key_data.action == PRESS:
//         new_x = game_struct.player_x
//         new_y = game_struct.player_y

//         if key_data.key == W:
//             new_y = new_y - 1
//         else if key_data.key == S:
//             new_y = new_y + 1
//         else if key_data.key == A:
//             new_x = new_x - 1
//         else if key_data.key == D:
//             new_x = new_x + 1

//         // Check if the new position is valid
//         if is_valid_move(game_struct, new_x, new_y):
//             game_struct.player_x = new_x
//             game_struct.player_y = new_y
//             game_struct.moves = game_struct.moves + 1
//             print("Moves: " + game_struct.moves)
//             redraw_map(game_struct)

