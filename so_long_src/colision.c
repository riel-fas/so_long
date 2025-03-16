/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:23:55 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/16 09:34:03 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool check_wall(t_game *game, int next_x, int next_y)
{
    int tile_x = next_x / TILE_SIZE;
    int tile_y = next_y / TILE_SIZE;

    // Check if the coordinates are within the map bounds
    if (tile_x < 0 || tile_x >= game->map_width || tile_y < 0 || tile_y >= game->map_height)
        return false;

    // Check if the next position is a wall ('1')
    if (game->map[tile_y][tile_x] == '1')
        return false;

    return true;
}

