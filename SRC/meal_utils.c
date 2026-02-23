/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:09:08 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/23 00:14:56 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
}

long	get_last_meal(t_philo	*philo)
{
	long	time;

	pthread_mutex_lock(&philo->meal_mutex);
	time = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_mutex);
	return(time);
}
