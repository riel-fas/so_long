/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:16:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/23 02:33:10 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/riel-fas/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>


typedef	struct	s_game
{
	mlx_t	*mlx;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;

}	t_game;

void	keyboard(mlx_key_data_t keydata, void *param);











#endif
