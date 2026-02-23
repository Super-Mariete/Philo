/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:47:03 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/23 01:53:55 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

int	take_forks(t_philo *philo)
{
	if(philo->id % 2 == 0)
	{	
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		if (!get_simulation_state(philo->data))
		{
			pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
			return(0);
		}
		printf("Philo %d took left fork\n", philo->id);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		if(!get_simulation_state(philo->data))
		{
			pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
			pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
			return(0);
		}	
		printf("Philo %d took right fork\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		if(!get_simulation_state(philo->data))
		{
			pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
			return(0);
		}
		printf("Philo %d took right fork\n", philo->id);
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		if(!get_simulation_state(philo->data))
		{
			pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
			pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
			return(0);
		}
		printf("Philo %d took left fork\n", philo->id);
	}
	return (1);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if(!data->forks)
		return (0);
	i = 0;
	while(i < data->nb_philo)
	{
		if(pthread_mutex_init(&data->forks[i] ,NULL) != 0)
			return(0);
		i++;
	}
	return(1);
}
