/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:31:43 by made-ped          #+#    #+#             */
/*   Updated: 2026/03/03 14:03:58 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"

static int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo && !data->someone_dead)
	{
		pthread_mutex_lock(&data->data_mutex);
		if (timestamp() - data->philos[i].last_meal > data->time_die)
		{
			data->someone_dead = 1;
			pthread_mutex_lock(&data->print);
			printf("%ld %d died\n", timestamp() - data->start_time, i + 1);
			pthread_mutex_unlock(&data->print);
			pthread_mutex_unlock(&data->data_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->data_mutex);
		i++;
	}
	return (0);
}

static int	check_all_ate(t_data *data)
{
	int	i;
	int	count;

	if (data->must_eat == -1)
		return (0);
	i = 0;
	count = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->data_mutex);
		if (data->philos[i].meals_eaten >= data->must_eat)
			count++;
		pthread_mutex_unlock(&data->data_mutex);
		i++;
	}
	if (count == data->nb_philo)
	{
		pthread_mutex_lock(&data->data_mutex);
		data->all_ate = 1;
		pthread_mutex_unlock(&data->data_mutex);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!data->all_ate && !data->someone_dead)
	{
		if (check_death(data))
			break ;
		if (check_all_ate(data))
			break ;
		usleep(500);
	}
	return (NULL);
}
