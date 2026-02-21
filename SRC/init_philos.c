/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:23:06 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/21 21:37:17 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	assing_philo(t_philo *philo, t_data *data, int index)
{
	philo->id = index + 1;
	philo->meals_eaten = 0;
	philo->data = data;
	philo->left_fork = index;
	philo->right_fork = (index + 1) % data->nb_philo;
}

void	init_philos(t_data *data)
{
	int i;

	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
	{
		write(2, "Malloc error\n", 13);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while(i < data->nb_philo)
	{
		assing_philo(&data->philos[i], data, i);
		i++;
		printf("Philo %d  iniciado correctamente\n", i);
	}
}
