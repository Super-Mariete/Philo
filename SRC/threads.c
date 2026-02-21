/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:20:06 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/21 22:48:39 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	usleep(1000);
	if(take_forks(philo))
	{
		philo->meals_eaten++;
		put_forks(philo);
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
