/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:31:43 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/22 20:42:40 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int	i;

	data = (t_data *)arg;
	while(get_simulation_state(data))
	{
		i = 0;
		while(i < data->nb_philo)
		{
			if(get_time() - data->philos[i].last_meal >
					data->time_die)
			{
				print_status(&data->philos[i], "died");
				stop_simulation(data);
				return(NULL);
			}
			i++;
		}
		usleep(100);
	}
	return(NULL);
}
