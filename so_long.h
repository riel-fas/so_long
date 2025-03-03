/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:16:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/03 16:11:19 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/riel-fas/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#define TILE_SIZE 64  // or whatever size you want your tiles to be


typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				map_width;
	int				map_height;
	int				player_x;
	int				player_y;
	int				collectibles;
	mlx_image_t		*player_img;
	mlx_texture_t	*player_texture;
	mlx_image_t		*map_image_1;
	mlx_texture_t	*map_texture_1;
	mlx_image_t		*map_image_0;
	mlx_texture_t	*map_texture_0;
	int				moves;
} t_game;

// void    keyboard(mlx_key_data_t keydata, void *param);
// void draw_map(t_game *game);
void keyboard(void *param);
void	load_map(t_game *game, char *path);

void	load_textures_01(t_game *game);

#endif
