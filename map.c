/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:44:51 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/01 05:20:04 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"


void	load_map(t_game *game, char *path)
{
	//open map file
	int		fd;
	int		width;
	int		height;
	int		line_size;
	int		x;
	int		row_x;
	int		column_y;
	char	*line;


	fd = open(path, O_RDONLY);
	if (!fd)
	{

		write (2, "ERROR OPENING FILE 'MAP'", 24);
		exit (EXIT_FAILURE);
	}
	//calculate map dimension
	//line by line
	//check map if rectangular
	height = 0;
	while ((line = get_next_line(fd)))
	{
		line_size = 0;
		while (line[line_size] && line[line_size] != '\n')
			line_size++;


    	// Debug print
    	printf("Line %d: %s (length: %d)\n", height + 1, line, line_size);

		if (width == 0)
			width = line_size;
		else if(width != line_size)
		{
			write (2, "ERROR: MAP IS NOT RECTANGULAR", 29);
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
		game->map[x] = malloc(sizeof(char *) * (width + 1));
		x++;
	}
	//we reopen the map file to read, then we store each line of the map in the **map in the struct
	fd = open(path, O_RDONLY);
	if (!fd)
	{
		write (2, "ERROR OPENING FILE 'MAP'", 24);
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
			else if (line[column_y] == 'C')
				game->collectibles++;
			column_y++;
		}
		game->map[row_x][column_y] = '\0';
		row_x++;
		free(line);
	}
	close (fd);
}
