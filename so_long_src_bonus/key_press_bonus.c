/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:38:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/25 08:03:06 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height || game->map.grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

static int	handle_tile(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.collected++;
		game->map.grid[new_y][new_x] = '0';
		update_render_map(game);
		if (game->map.collected == game->map.collectibles)
		{
			game->map.grid[game->map.exit_y][game->map.exit_x] = 'E';
			game->exit_instance = mlx_image_to_window(game->mlx, game->exit_img,
					game->map.exit_x * TILE_SIZE, game->map.exit_y * TILE_SIZE);
			update_render_map(game);
		}
	}
	else if (new_x == game->map.exit_x && new_y == game->map.exit_y
		&& game->map.collected == game->map.collectibles
		&& game->map.grid[new_y][new_x] == 'E')
	{
		ft_printf("SSAAALLLLIIIIINNNNNNAAAAAAA! Moves: %d\n", game->moves + 1);
		mlx_close_window(game->mlx);
		return (0);
	}
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	if (game->map.grid[new_y][new_x] == 'X')
	{
		ft_printf("Game Over!! Moves: %d\n", game->moves + 1);
		mlx_close_window(game->mlx);
		return ;
	}
	if (!handle_tile(game, new_x, new_y))
		return ;
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
	game->moves++;
	update_move_counter(game);
	update_render_map(game);
	ft_printf("Moves: %d\n", game->moves);
}

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

void	update_move_counter(t_game *game)
{
	char	*move_str;
	char	*display_str;

	move_str = ft_itoa(game->moves);
	display_str = ft_strjoin_bonus("MOVES : ", move_str);
	mlx_delete_image(game->mlx, game->move_counter_img);
	game->move_counter_img = mlx_put_string(game->mlx, display_str, 10, 10);
	free(display_str);
}
