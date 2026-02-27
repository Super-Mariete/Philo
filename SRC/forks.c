/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:47:03 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/27 19:42:30 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"
/*
int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock (&philo->data->forks[philo->left_fork]);
		if (!get_simulation_state(philo->data))
		{
			pthread_mutex_unlock (&philo->data->forks[philo->left_fork]);
			return (0);
		}
		print_status (philo, "has taken a fork");
		pthread_mutex_lock (&philo->data->forks[philo->right_fork]);
		if (!get_simulation_state(philo->data))
		{
			pthread_mutex_unlock (&philo->data->forks[philo->right_fork]);
			pthread_mutex_unlock (&philo->data->forks[philo->left_fork]);
			return (0);
		}
		print_status (philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock (&philo->data->forks[philo->right_fork]);
		if (!get_simulation_state(philo->data))
		{
			pthread_mutex_unlock (&philo->data->forks[philo->right_fork]);
			return (0);
		}
		print_status (philo, "has taken a fork");
		pthread_mutex_lock (&philo->data->forks[philo->left_fork]);
		if (!get_simulation_state(philo->data))
		{
			pthread_mutex_unlock (&philo->data->forks[philo->left_fork]);
			pthread_mutex_unlock (&philo->data->forks[philo->right_fork]);
			return (0);
		}
		print_status (philo, "has taken a fork");
	}
	return (1);
}
*/

int	lock_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->data->forks[fork_id]);
	if (!get_simulation_state(philo->data))
	{
		pthread_mutex_unlock(&philo->data->forks[fork_id]);
		return (0);
	}
	print_status(philo, "has taken a fork");
	return (1);
}

int	take_forks(t_philo *philo)
{
	int	first;
	int	second;

	if (philo->id % 2 == 0)
	{first = philo->left_fork; second = philo->right_fork;}
	else
	{first = philo->right_fork; second = philo->left_fork;}
	if (!lock_fork(philo, first))
		return (0);
	if (!lock_fork(philo, second))
	{
		pthread_mutex_unlock(&philo->data->forks[first]);
		return (0);
	}
	return (1);
}
void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock (&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock (&philo->data->forks[philo->right_fork]);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc (sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init (&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy (&data->forks[i]);
			free (data->forks);
			return (0);
		}
		i++;
	}
	return (1);
}
