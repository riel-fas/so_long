/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handl_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:49:02 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/24 10:13:39 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	size_t	len;
	char	*copy;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, len);
	ft_strlcat(copy, s2, len);
	free(s2);
	return (copy);
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
