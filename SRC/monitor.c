/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:31:43 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/27 19:54:17 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"
/*
void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;
	int		full;
	long	last_meal;
	long	time_last_meal;

	data = (t_data *)arg;
	usleep (1000);
	while (get_simulation_state(data))
	{
		i = 0;
		full = 1;
		while (i < data->nb_philo)
		{
			pthread_mutex_lock (&data->philos[i].meal_mutex);
			last_meal = data->philos[i].last_meal;
			pthread_mutex_unlock (&data->philos[i].meal_mutex);
			time_last_meal = get_time() - last_meal;
			if (time_last_meal > data->time_die)
			{
				print_status (&data->philos[i], "died");
				stop_simulation (data);
				return (NULL);
			}
			if (data->must_eat != -1)
			{
				pthread_mutex_lock (&data->philos[i].meal_mutex);
				if (data->philos[i].meals_eaten < data->must_eat)
					full = 0;
				pthread_mutex_unlock (&data->philos[i].meal_mutex);
			}
			i++;
		}
		if (data->must_eat != -1 && full)
		{
			stop_simulation (data);
			return (NULL);
		}
		usleep (1000);
	}
	return (NULL);
}*/

int	check_philo(t_data *data, int i, int *full)
{
	long	last_meal;

	pthread_mutex_lock(&data->philos[i].meal_mutex);
	last_meal = data->philos[i].last_meal;
	if (data->must_eat != -1 && data->philos[i].meals_eaten < data->must_eat)
		*full = 0;
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	if (get_time() - last_meal > data->time_die)
	{
		print_status(&data->philos[i], "died");
		stop_simulation(data);
		return (0);
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;
	int		full;

	data = (t_data *)arg;
	usleep(1000);
	while (get_simulation_state(data))
	{
		i = -1;
		full = 1;
		while (++i < data->nb_philo)
			if (!check_philo(data, i, &full))
				return (NULL);
		if (data->must_eat != -1 && full)
		{
			stop_simulation(data);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
