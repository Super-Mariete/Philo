/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:20:06 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/22 19:17:51 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(philo->data->simulation_running)
	{
		take_forks(philo);
		printf("Philo %d is eating\n", philo->id);
		usleep(philo->data->time_eat * 1000);
		put_forks(philo);
		printf("Philo %d is sleeping\n", philo->id);
		usleep(philo->data->time_sleep * 1000);
		printf("Philo %d is thinking\n", philo->id);
	}
	return(NULL);
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if(pthread_create(&data->philos[i].thread, NULL, philo_routine,
				&data->philos[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while(i < data->nb_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	return (1);
}
