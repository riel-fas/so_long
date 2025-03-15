/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:44:51 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/15 16:28:59 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/get_next_line/get_next_line.h"

void	load_map(t_game *game, char *path)
{
	//open map file
	int		fd;
	int		width;
	int		height;
	int		line_size;//////
	int		x;
	int		row_x;
	int		column_y;
	char	*line;//////

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write (2, "ERROR OPENING MAP FILE\n", 23);
		exit (EXIT_FAILURE);
	}
	//calculate map dimension //line by line //check map if rectangular
	width = 0;/////
	height = 0;////

	while ((line = get_next_line(fd)))
	{
		line_size = 0;
		while (line[line_size] && line[line_size] != '\n')
			line_size++;

		if (width == 0)
			width = line_size;//we determine line width using first line

		else if(width != line_size)
		{
			write (2, "ERROR: MAP IS NOT RECTANGULAR\n", 30);
			free(line);
			close (fd);
			exit(EXIT_FAILURE);
		}
		height++;
		free(line);
	}
	close (fd);
	//update maps dimensions
	game->map_height = height;
	game->map_width = width;
	//alocate enough for all map lines
	//we read from map file the second time to store it in a buffer
	x = 0;
	game->map = malloc(sizeof(char *) * height);
	while (x < height)
	{
		game->map[x] = malloc(sizeof(char) * (width + 1));
		x++;
	}
	//we reopen the map file to read, then we store each line of the map in the **map in the struct
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write (2, "ERROR OPENING FILE 'MAP'\n", 25);
		exit (EXIT_FAILURE);
	}
	row_x = 0;
	while ((line = get_next_line(fd)))
	{
		column_y = 0;
		while (line[column_y] && line[column_y] != '\n')
		{
			game->map[row_x][column_y] = line[column_y];
			//player start point in the map
			if (line[column_y] == 'P')
			{
				game->player_x = row_x;
				game->player_y = column_y;
			}
			//collectibles
			// else if (line[column_y] == 'C')
			// 	game->collectibles++;
			column_y++;
		}
		game->map[row_x][column_y] = '\0';
		row_x++;
		free(line);
	}
	close (fd);
}

void	load_textures_01(t_game *game)
{
	int row;
	int column;
	int x;
	int y;

	row = 0;
	x = 0;
	y = 0;
	column = 0;
	game->map_texture_1 = mlx_load_png("textures/1/wall2.png");
	game-> map_image_1 = mlx_texture_to_image(game->mlx, game->map_texture_1);

	game->map_texture_0 = mlx_load_png("textures/0/tile_004055.png");
	game-> map_image_0 = mlx_texture_to_image(game->mlx, game->map_texture_0);

	while (row < game->map_height)
	{
		column = 0;
		while  (column < game->map_width)
		{
			if (game->map[row][column] == '1')
			{
				x = column * TILE_SIZE;
				y = row * TILE_SIZE;
				mlx_image_to_window(game->mlx, game->map_image_1, x, y);
			}
			if (game->map[row][column] == '0')
			{
				x = column * TILE_SIZE;
				y = row * TILE_SIZE;
				mlx_image_to_window(game->mlx, game->map_image_0, x, y);
			}
			column++;
		}
		row++;
	}
}
