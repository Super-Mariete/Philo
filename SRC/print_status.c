/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:46:01 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/25 21:37:33 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"

void	print_status(t_philo *philo, char *msg)
{
	long	time;

	pthread_mutex_lock (&philo->data->print_mutex);
	if (get_simulation_state(philo->data) || ft_strcmp(msg, "died") == 0)
	{
		time = get_time () - philo->data->start_time;
		printf ("%ld %d %s\n", time, philo->id, msg);
	}
	pthread_mutex_unlock (&philo->data->print_mutex);
}
