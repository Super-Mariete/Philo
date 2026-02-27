/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:44:56 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/27 21:01:35 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INC/philosopher.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_control_error (argc, argv))
		return (ft_error("Error arguments"), EXIT_FAILURE);
	if (!ft_init_data (&data, argv))
		return (ft_error("Error limit"), EXIT_FAILURE);
	if (!init_philos (&data))
		return (ft_error_free("Error philos", &data), EXIT_FAILURE);
	if (!init_forks(&data))
		return (ft_error_free("Error mutex", &data), EXIT_FAILURE);
	if (!init_simulation(&data))
		return (ft_error_free("Error simulation", &data), EXIT_FAILURE);
	if (!create_threads (&data))
		return (ft_error_free("Error threads", &data), EXIT_FAILURE);
	free_data (&data);
	return (EXIT_SUCCESS);
}
