/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:47:03 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/21 22:49:50 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

int	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->left_fork;
	right = philo->right_fork;
	printf("Philo %d checking forks %d and %d\n", philo->id, left, right);
	if(philo->data->forks[left] == 0 && philo->data->forks[right] == 0)
	{
		printf("Philo %d sees forks free\n", philo->id);
		usleep(1000);
		philo->data->forks[left] = 1;
		philo->data->forks[right] = 1;
		printf("Philo %d took forks %d & %d\n", philo->id, left, right);
		return (1);
	}
	printf("Philo %d could not take forks\n", philo->id);
	return (0);
}

void	put_forks(t_philo *philo)
{
	printf("Philo %d releasing forks %d & %d\n", philo->id, philo->left_fork, 
		philo->right_fork);
	philo->data->forks[philo->left_fork] = 0;
	philo->data->forks[philo->right_fork] = 0;
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
