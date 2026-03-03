/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:23:06 by made-ped          #+#    #+#             */
/*   Updated: 2026/03/03 14:03:02 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"

static int	alloc_everything(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	return (0);
}

static int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	if (pthread_mutex_init(&data->data_mutex, NULL))
		return (1);
	return (0);
}

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i;
		data->philos[i].left_fork = i;
		data->philos[i].rigth_fork = (i + 1) % data->nb_philo;
		data->philos[i].meals_eaten = 0;
		data->philos[i].data = data;
		i++;
	}
}

static int	parse_and_fill(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	if (data->nb_philo < 1 || data->time_die < 1 || data->time_eat < 1
		|| data->time_sleep < 1 || (argc == 6 && data->must_eat < 1))
		return (1);
	data->someone_dead = 0;
	data->all_ate = 0;
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (parse_and_fill(data, argc, argv))
		return (cleanup(NULL, "Invalid arguments"));
	if (alloc_everything(data))
		return (cleanup(NULL, "Malloc error"));
	if (init_mutexes(data))
		return (cleanup(data, "Mutex init error"));
	init_philos(data);
	return (0);
}
