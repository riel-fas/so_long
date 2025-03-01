/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:44:51 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/01 06:30:56 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"


// void	load_map(t_game *game, const char *path)
// {
// 	//open map file
// 	int		fd;
// 	int		width;
// 	int		height;
// 	int		line_size;
// 	int		x;
// 	int		row_x;
// 	int		column_y;
// 	char	*line;


// 	fd = open(path, O_RDONLY);
// 	if (!fd)
// 	{

// 		write (2, "ERROR OPENING FILE 'MAP'", 24);
// 		exit (EXIT_FAILURE);
// 	}
// 	//calculate map dimension
// 	//line by line
// 	//check map if rectangular
// 	height = 0;
// 	while ((line = get_next_line(fd)))
// 	{
// 		line_size = 0;
// 		while (line[line_size] && line[line_size] != '\n')
// 			line_size++;

// 		if (width == 0)
// 			width = line_size;
// 		else if(width != line_size)
// 		{
// 			write (2, "ERROR: MAP IS NOT RECTANGULAR", 29);
// 			free(line);
// 			close (fd);
// 			exit(EXIT_FAILURE);
// 		}
// 		height++;
// 		free(line);
// 	}
// 	close (fd);
// 	//update maps dimensions
// 	game->map_height = height;
// 	game->map_width = width;
// 	//alocate enough for all map lines
// 	//we read from map file the second time to store it in a buffer
// 	x = 0;
// 	game->map = malloc(sizeof(char *) * height);
// 	while (x < height)
// 	{
// 		game->map[x] = malloc(sizeof(char *) * (width + 1));
// 		x++;
// 	}
// 	//we reopen the map file to read, then we store each line of the map in the **map in the struct
// 	fd = open(path, O_RDONLY);
// 	if (!fd)
// 	{
// 		write (2, "ERROR OPENING FILE 'MAP'", 24);
// 		exit (EXIT_FAILURE);
// 	}
// 	row_x = 0;
// 	while ((line = get_next_line(fd)))
// 	{
// 		column_y = 0;
// 		while (line[column_y] && line[column_y] != '\n')
// 		{
// 			game->map[row_x][column_y] = line[column_y];
// 			//player start point in the map
// 			if (line[column_y] == 'P')
// 			{
// 				game->player_x = row_x;
// 				game->player_y = column_y;
// 			}
// 			//collectibles
// 			else if (line[column_y] == 'C')
// 				game->collectibles++;
// 			column_y++;
// 		}
// 		game->map[row_x][column_y] = '\0';
// 		row_x++;
// 		free(line);
// 	}
// 	close (fd);
// }


void	load_map(t_game *game, const char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open map file\n");
        exit(EXIT_FAILURE);
    }

    char *line;
    int width = 0;
    int height = 0;

    // First pass: Calculate map dimensions
    while ((line = get_next_line(fd))) {
        printf("Line %d: %s\n", height + 1, line); // Debug print

        int line_length = 0;
        while (line[line_length] && line[line_length] != '\n') {
            line_length++;
        }

        if (width == 0) {
            width = line_length; // First line determines the width
        } else if (line_length != width) {
            printf("Error: Map is not rectangular (expected width: %d, actual width: %d)\n", width, line_length);
            free(line);
            close(fd);
            exit(EXIT_FAILURE);
        }

        height++;
        free(line); // Free the line after processing
    }

    close(fd);

    // Store the map dimensions in the game struct
    game->map_width = width;
    game->map_height = height;

    // Allocate memory for the map
    game->map = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        game->map[i] = (char *)malloc((width + 1) * sizeof(char)); // +1 for null terminator
    }

    // Second pass: Read the map into the 2D array
    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open map file\n");
        exit(EXIT_FAILURE);
    }

    int row = 0;
    while ((line = get_next_line(fd))) {
        int col = 0;
        while (line[col] && line[col] != '\n') {
            game->map[row][col] = line[col];
            col++;
        }
        game->map[row][col] = '\0'; // Null-terminate the row
        row++;
        free(line); // Free the line after processing
    }

    close(fd);
}
