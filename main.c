/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:44:56 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/24 01:52:31 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"INC/philosopher.h"

int main(int argc, char **argv)
{
	t_data	data;

	ft_control_error(argc, argv);
	ft_init_data(&data, argv);
	init_philos(&data);
	if(!init_forks(&data))
	{
		write(2, "Error create mutex\n", 19);
		free_data(&data);
		return(EXIT_FAILURE);
	}
	if(!init_simulation(&data))
	{
//	return(error_exit("Error: simulatio failed\n", 1));
		write(2, "Error simulation failed\n", 24);
		free_data(&data);
		return(EXIT_FAILURE);
	}
	if(!create_threads(&data))
	{
		write(2, "Error create threads\n", 21);
		free_data(&data);
		return(EXIT_FAILURE);
	}
	free_data(&data);
	return(EXIT_SUCCESS);
}
