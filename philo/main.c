/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:44:56 by made-ped          #+#    #+#             */
/*   Updated: 2026/03/03 20:59:08 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INC/philosopher.h"

static int	create_threads(t_data *data)
{
	int	i;

	data->start_time = get_time();
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].last_meal = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]))
			return (clean(data, "pthread_create error"));
		i++;
	}
	return (0);
}

static int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (clean(data, "pthread_join error"));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor_th;

	if (init_data(&data, argc, argv))
		return (1);
	if (create_threads(&data))
		return (1);
	if (pthread_create(&monitor_th, NULL, &monitor, &data))
		return (clean(&data, "monitor thread error"));
	if (pthread_join(monitor_th, NULL))
		return (clean(&data, "monitor join error"));
	join_threads(&data);
	clean(&data, NULL);
	return (0);
}
