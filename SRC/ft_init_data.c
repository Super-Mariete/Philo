/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:54:44 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/21 20:54:47 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	ft_init_data(t_data *data, char **argv)
{
	int i;
	long	value;

	i = 1;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		if(value <= 0 || value >= INT_MAX)
		{
			write(2, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
		if(i == 1)
			data->nb_philo = (int)value;
		else if(i == 2)
			data->time_die = (int)value;
		else if(i == 3)
			data->time_eat = (int)value;
		else if(i == 4)
			data->time_sleep = (int)value;
		else if(i == 5)
			data->must_eat = (int)value;
		i++;
	}
	printf("data iniciada\n");
}
