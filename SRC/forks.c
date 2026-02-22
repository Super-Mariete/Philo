/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:47:03 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/22 18:45:35 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	printf("Philo %d took left fork\n", philo->id);
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	printf("Philo %d took right fork\n", philo->id);
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
/*
int	simulate(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nb_philo)
	{
		if(take_forks(&data->philos[i]))
		{
			data->philos[i].meals_eaten++;
			put_forks(&data->philos[i]);
		}
		i++;
	}
	return (1);
}*/
