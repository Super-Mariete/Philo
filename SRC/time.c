/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:05:00 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/25 21:47:36 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday (&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_sleep(t_data *data, long duration_ms)
{
	long	start;

	start = get_time ();
	while (get_time() - start < duration_ms)
	{
		if (!get_simulation_state(data))
			break ;
		if ((duration_ms - (get_time () - start)) > 10)
			usleep (500);
		else
			usleep (100);
	}
}
