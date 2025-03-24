/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:49:02 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/24 10:13:35 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
		{
			if (game->map.grid[i])
				free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
}

void	exit_with_error(char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	handle_window_close(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

int		map_ber(char *map_path)
{
	int i;

	i = 0;
	if (!(ft_strlen(map_path) > 4))
		return 0;
	while (map_path[i])
		i++;
	i--;
	if (!(map_path[i] == 'r' && map_path[i-1] == 'e' && map_path[i-2] == 'b' && map_path[i-3] == '.'))
	{
		write(2, "FILE IS NOT .ber\n", 17);
		return 0;
	}
	return (1);
}
