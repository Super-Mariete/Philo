/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:48:28 by made-ped          #+#    #+#             */
/*   Updated: 2026/03/04 18:23:02 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"

static void	destroy_mutexes(t_data *data)
{
	int	i;

	if (!data->forks)
		return ;
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->data_mutex);
}

int	clean(t_data *data, char *msg)
{
	if (msg)
	{
		int i;

		i = 0;
		while(msg[i])
			i++;
		write(2, "Error: ", 7);
		write(2, msg, i);
		write(2, "\n", 1);
	}
	if (data)
	{
		destroy_mutexes(data);
		if (data->philos)
			free(data->philos);
		if (data->forks)
			free(data->forks);
	}
	if (msg)
		return (1);
	return (0);
}
