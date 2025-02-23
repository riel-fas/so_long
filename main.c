/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:19:52 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/23 02:35:18 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{

	t_game game;

	//MLX inis. and window opening
	game.mlx = mlx_init(1000, 1000, "the fucking_window", true);
	if (!game.mlx)
		return (EXIT_FAILURE);



	//key hook
	mlx_key_hook(game.mlx, keyboard, &game);



	//MLX event loop
	mlx_loop(game.mlx);






	//Clean and exit
	mlx_terminate(game.mlx);

	return (EXIT_SUCCESS);
}
