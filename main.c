/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:44:56 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/25 22:40:44 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INC/philosopher.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_control_error (argc, argv))
	{
		write (2, "Error arguments\n", 16);
		return (EXIT_FAILURE);
	}
	if (!ft_init_data (&data, argv))
	{
		write (2, "Error limit\n", 12);
		return (EXIT_FAILURE);
	}
	if (!init_philos (&data))
	{
		write (2, "Malloc error\n", 13);
		return (EXIT_FAILURE);
	}
	if (!init_forks(&data))
	{
		write (2, "Error create mutex\n", 19);
		free_data (&data);
		return (EXIT_FAILURE);
	}
	if (!init_simulation(&data))
	{
		write (2, "Error simulation failed\n", 24);
		free_data (&data);
		return (EXIT_FAILURE);
	}
	if (!create_threads (&data))
	{
		write (2, "Error create threads\n", 21);
		free_data (&data);
		return (EXIT_FAILURE);
	}
	free_data (&data);
	return (EXIT_SUCCESS);
}
