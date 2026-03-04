/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:09:08 by made-ped          #+#    #+#             */
/*   Updated: 2026/03/04 18:41:39 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_usleep(long time, t_data *data)
{
	long	start;

	start = get_time();
	while (!data->someone_dead && (get_time() - start) < time)
		usleep(200);
}

void	print_status(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&data->print);
	if (!data->someone_dead && !data->all_ate)
		printf("%ld %d %s\n", get_time() - data->start_time, id + 1, str);
	pthread_mutex_unlock(&data->print);
}
