/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 08:36:01 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/25 08:39:34 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_game_over(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == 'X')
	{
		ft_printf("Game Over!! Moves: %d\n", game->moves + 1);
		mlx_close_window(game->mlx);
	}
}

int	handle_move(t_game *game, int new_x, int new_y)
{
	if (!handle_tile(game, new_x, new_y))
		return (0);
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	if (game->map.player_x == game->map.exit_x
		&& game->map.player_y == game->map.exit_y
		&& game->map.collected == game->map.collectibles)
		game->map.grid[game->map.exit_y][game->map.exit_x] = 'E';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	if (!(new_x == game->map.exit_x && new_y == game->map.exit_y
			&& game->map.collected == game->map.collectibles))
		game->map.grid[new_y][new_x] = 'P';
	return (1);
}

void	update_game_state(t_game *game)
{
	game->moves++;
	update_move_counter(game);
	update_render_map(game);
	ft_printf("Moves: %d\n", game->moves);
}
