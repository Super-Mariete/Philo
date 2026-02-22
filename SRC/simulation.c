/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:40:53 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/22 20:28:46 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

int	get_simulation_state(t_data *data)
{
	int status;

	pthread_mutex_lock(&data->stop_mutex);
	status = data->simulation_running;
	pthread_mutex_unlock(&data->stop_mutex);
	return(status);
}

void	stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	data->simulation_running = 0;
	pthread_mutex_unlock(&data->stop_mutex);
}

int	init_simulation(t_data *data)
{
	data->start_time = get_time();
	data->simulation_running = 1;
	if(pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return(0);
	if(pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return(0);
	return(1);
}
