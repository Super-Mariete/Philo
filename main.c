/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:44:56 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/21 20:49:43 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"INC/philosopher.h"

int main(int argc, char **argv)
{
	t_data	data;

	ft_control_error(argc, argv);
	ft_init_data(&data, argv);
	init_philos(&data);
	free_data(&data);
	return(EXIT_SUCCESS);
}
