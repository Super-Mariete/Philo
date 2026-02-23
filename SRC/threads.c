/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:20:06 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/23 02:11:32 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->stop_mutex);
	philo->last_meal = philo->data->start_time;
	pthread_mutex_unlock(&philo->data->stop_mutex);
	if(philo->id % 2 == 0)
		usleep(1000);
	while(get_simulation_state(philo->data))
	{
		take_forks(philo);
		set_last_meal(philo);
		pthread_mutex_lock(&philo->meal_mutex);
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_mutex);
		print_status(philo, "is eating");
		usleep(philo->data->time_eat * 1000);
		put_forks(philo);
		print_status(philo, "is sleeping");
		usleep(philo->data->time_sleep * 1000);
		print_status(philo, "is thinking");
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
	if(pthread_create(&data->monitor_thread, NULL, monitor_routine, data) != 0)
		return(0);
	i = 0;
	while(i < data->nb_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(data->monitor_thread, NULL);
	return (1);
}
