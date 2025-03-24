/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:38:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/24 13:57:34 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height || game->map.grid[new_y][new_x] == '1')
		return (0);
	return (1);
}
// Update the handle_tile function
static int handle_tile(t_game *game, int new_x, int new_y)
{
    // Check if we're stepping on a collectible
    if (game->map.grid[new_y][new_x] == 'C')
    {
        game->map.collected++;
        game->map.grid[new_y][new_x] = '0'; // Remove collectible
        update_render_map(game);
        ft_printf("Collectibles: %d/%d\n", game->map.collected, game->map.collectibles);

        // Reveal the exit if all collectibles are collected
// Reveal the exit if all collectibles are collected
		if (game->map.collected == game->map.collectibles)
		{
    		game->map.grid[game->map.exit_y][game->map.exit_x] = 'E';

		    // Create the exit image instance when revealing the exit
    		game->exit_instance = mlx_image_to_window(game->mlx, game->exit_img,
                          game->map.exit_x * TILE_SIZE,
                          game->map.exit_y * TILE_SIZE);

    		update_render_map(game);
    		ft_printf("Exit is now visible!\n");
		}
    }
    // Check if player is at exit position and has collected all collectibles
    else if (new_x == game->map.exit_x && new_y == game->map.exit_y &&
             game->map.collected == game->map.collectibles &&
             game->map.grid[new_y][new_x] == 'E')
    {
        ft_printf("You win! Moves: %d\n", game->moves + 1);
        mlx_close_window(game->mlx);
        return (0);
    }
    return (1);
}

// Update the move_player function
void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->map.player_x + dx;
    int new_y = game->map.player_y + dy;

    if (!is_valid_move(game, new_x, new_y))
        return;

    if (!handle_tile(game, new_x, new_y))
        return;

    // Clear the previous player position
    game->map.grid[game->map.player_y][game->map.player_x] = '0';

    // If we just left the exit position, restore exit if needed
    if (game->map.player_x == game->map.exit_x &&
        game->map.player_y == game->map.exit_y &&
        game->map.collected == game->map.collectibles)
    {
        game->map.grid[game->map.exit_y][game->map.exit_x] = 'E';
    }

    // Update player position
    game->map.player_x = new_x;
    game->map.player_y = new_y;

    // Set the new player position in the grid, unless it's the exit
    if (!(new_x == game->map.exit_x && new_y == game->map.exit_y &&
          game->map.collected == game->map.collectibles))
    {
        game->map.grid[new_y][new_x] = 'P';
    }

    game->moves++;
    update_render_map(game);
    ft_printf("Moves: %d\n", game->moves);
}

// static int	handle_tile(t_game *game, int new_x, int new_y)
// {
// 	if (game->map.grid[new_y][new_x] == 'C')
// 	{
// 		game->map.collected++;
// 		game->map.grid[new_y][new_x] = '0';
// 		update_render_map(game);
// 	}
// 	else if (game->map.grid[new_y][new_x] == 'E')
// 	{
// 		if (game->map.collected == game->map.collectibles)
// 		{
// 			ft_printf("You win! Moves: %d\n", game->moves + 1);
// 			mlx_close_window(game->mlx);
// 			return (0);
// 		}
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// void	move_player(t_game *game, int dx, int dy)
// {
// 	int	new_x;
// 	int	new_y;

// 	new_x = game->map.player_x + dx;
// 	new_y = game->map.player_y + dy;
// 	if (!is_valid_move(game, new_x, new_y))
// 		return ;
// 	if (!handle_tile(game, new_x, new_y))
// 		return ;
// 	game->map.grid[game->map.player_y][game->map.player_x] = '0';
// 	game->map.player_x = new_x;
// 	game->map.player_y = new_y;
// 	game->map.grid[new_y][new_x] = 'P';
// 	game->moves++;
// 	update_render_map(game);
// 	ft_printf("Moves: %d\n", game->moves);
// }

// void move_player(t_game *game, int dx, int dy)
// {
//     int new_x = game->map.player_x + dx;
//     int new_y = game->map.player_y + dy;

//     if (!is_valid_move(game, new_x, new_y))
//         return;

//     if (!handle_tile(game, new_x, new_y))
//         return;

//     // Restore the exit tile if the player moves off it
//     if (game->map.grid[game->map.player_y][game->map.player_x] == 'P' &&
//         game->map.exit_x == game->map.player_x &&
//         game->map.exit_y == game->map.player_y &&
//         game->map.collected == game->map.collectibles)
//     {
//         game->map.grid[game->map.player_y][game->map.player_x] = 'E';
//     }
//     else
//     {
//         game->map.grid[game->map.player_y][game->map.player_x] = '0';
//     }

//     game->map.player_x = new_x;
//     game->map.player_y = new_y;

//     // Ensure the player tile is updated
//     if (game->map.grid[new_y][new_x] != 'E')
//         game->map.grid[new_y][new_x] = 'P';

//     game->moves++;
//     update_render_map(game);
//     ft_printf("Moves: %d\n", game->moves);
// }


void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, 1, 0);
		else if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	}
}
