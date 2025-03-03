/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:19:52 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/03 18:02:43 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_game game;
	int x;
	char *path = "maps/map1.ber";
	char *player_texture = "textures/player/frame66.png";


	//map
	load_map(&game, path);

    // Print the map (for debugging) // just to be sure
	x = 0;
	while (x < game.map_height)
	{
        printf("%s\n", game.map[x]);
		x++;
	}

// Initialize MLX and create a window
	game.mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, "so_long", true);
	if (!game.mlx)
	{
		return (EXIT_FAILURE);
		x = 0;
		//free map from memory
		while (x < game.map_height)
		{
			free(game.map[x]);
			x++;
		}
	}

	load_textures_01(&game);

	//load player texture
	game.player_texture = mlx_load_png(player_texture);
	if (!game.player_texture)
	{
		exit(EXIT_FAILURE);
		//free map + teminate
	}
	game.player_img = mlx_texture_to_image(game.mlx, game.player_texture);
	if (!game.player_img)
	{
		return (EXIT_FAILURE);
		//freee

	}
	mlx_image_to_window(game.mlx, game.player_img, 200, 200);

	// game.player_img = mlx_new_image(game.mlx, 50, 50);



	////////////////////////////////////////////////////////////
	// Register the key hook
	// mlx_key_hook(game.mlx, keyboard, &game);
	mlx_loop_hook(game.mlx, keyboard, &game);
	// Draw the initial map
	// draw_map(&game);

	// Start the MLX event loop
	mlx_loop(game.mlx);


	////need to free map from memory + delete the texture then we terminate mlx

	// Clean up and exit
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}


















































// #include "so_long.h"

// int main() {
//     t_game game;

//     // Initialize game state
//     game.collectibles = 0;

//     // Load the map
//     load_map(&game, "/Users/riel-fas/Desktop/sso_long/maps/map1.ber");

//     // Print the map (for debugging)
//     printf("Map loaded successfully!\n");
//     printf("Map dimensions: %d (width) x %d (height)\n", game.map_width, game.map_height);
//     for (int i = 0; i < game.map_height; i++) {
//         printf("%s\n", game.map[i]);
//     }

//     // Initialize MLX and create a window
//     game.mlx = mlx_init(700, 700, "so_long", true);
//     if (!game.mlx) {
//         // Free the map memory before exiting
//         for (int i = 0; i < game.map_height; i++) {
//             free(game.map[i]);
//         }
//         free(game.map);
//         printf("Error: Failed to initialize MLX\n");
//         return (EXIT_FAILURE);
//     }

//     // Load player texture
//     game.player_texture = mlx_load_png("/Users/riel-fas/Desktop/frame66.png");
//     if (!game.player_texture) {
//         // Free the map memory and terminate MLX before exiting
//         for (int i = 0; i < game.map_height; i++) {
//             free(game.map[i]);
//         }
//         free(game.map);
//         mlx_terminate(game.mlx);
//         printf("Error: Could not load player texture\n");
//         return (EXIT_FAILURE);
//     }

//     // Convert texture to image
//     game.player_img = mlx_texture_to_image(game.mlx, game.player_texture);
//     if (!game.player_img) {
//         // Free the map memory, delete texture, and terminate MLX before exiting
//         for (int i = 0; i < game.map_height; i++) {
//             free(game.map[i]);
//         }
//         free(game.map);
//         mlx_delete_texture(game.player_texture);
//         mlx_terminate(game.mlx);
//         printf("Error: Could not convert texture to image\n");
//         return (EXIT_FAILURE);
//     }

//     // Place the player at the starting position
//     // mlx_image_to_window(game.mlx, game.player_img, game.player_x * TILE_SIZE, game.player_y * TILE_SIZE);
// 	mlx_image_to_window(game.mlx, game.player_img, 200, 200);
//     // Start the MLX event loop
//     mlx_loop(game.mlx);

//     // Clean up and exit
//     for (int i = 0; i < game.map_height; i++) {
//         free(game.map[i]);
//     }
//     free(game.map);
//     mlx_delete_texture(game.player_texture);
//     mlx_terminate(game.mlx);
//     return (EXIT_SUCCESS);
// }


// int main() {
//     t_game game;

//     // Initialize game state
//     game.collectibles = 0;

//     // Load the map
//     load_map(&game, "/Users/riel-fas/Desktop/sso_long/maps/map1.ber");

//     // Print the map (for debugging)
//     printf("Map loaded successfully!\n");
//     printf("Map dimensions: %d (width) x %d (height)\n", game.map_width, game.map_height);
//     for (int i = 0; i < game.map_height; i++) {
//         printf("%s\n", game.map[i]);
//     }

//     // Initialize MLX and create a window
//     game.mlx = mlx_init(700, 700, "so_long", true);
//     if (!game.mlx) {
//         // Free the map memory before exiting
//         for (int i = 0; i < game.map_height; i++) {
//             free(game.map[i]);
//         }
//         free(game.map);
//         printf("Error: Failed to initialize MLX\n");
//         return (EXIT_FAILURE);
//     }

//     // Load player texture
//     game.player_texture = mlx_load_png("/Users/riel-fas/Desktop/frame66.png");
//     if (!game.player_texture) {
//         // Free the map memory and terminate MLX before exiting
//         for (int i = 0; i < game.map_height; i++) {
//             free(game.map[i]);
//         }
//         free(game.map);
//         mlx_terminate(game.mlx);
//         printf("Error: Could not load player texture\n");
//         return (EXIT_FAILURE);
//     }

//     // Convert texture to image
//     game.player_img = mlx_texture_to_image(game.mlx, game.player_texture);
//     if (!game.player_img) {
//         // Free the map memory, delete texture, and terminate MLX before exiting
//         for (int i = 0; i < game.map_height; i++) {
//             free(game.map[i]);
//         }
//         free(game.map);
//         mlx_delete_texture(game.player_texture);
//         mlx_terminate(game.mlx);
//         printf("Error: Could not convert texture to image\n");
//         return (EXIT_FAILURE);
//     }

//     // Place the player at the starting position
//     mlx_image_to_window(game.mlx, game.player_img, 200, 200);

//     // Register the keyboard function as a loop hook
//     mlx_loop_hook(game.mlx, keyboard, &game);
//     printf("Keyboard function registered\n"); // Debug print

//     // Start the MLX event loop
//     printf("Starting MLX loop\n"); // Debug print
//     mlx_loop(game.mlx);

//     // Clean up and exit
//     for (int i = 0; i < game.map_height; i++) {
//         free(game.map[i]);
//     }
//     free(game.map);
//     mlx_delete_texture(game.player_texture);
//     mlx_terminate(game.mlx);
//     return (EXIT_SUCCESS);
// }
