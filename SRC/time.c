/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:05:00 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/24 13:44:58 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

long	get_time(void)
{
	struct	timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
/*
void	precise_sleep(t_data *data, long duration_ms)
{
	long	start;
	long	elapsed;

	start = get_time();
	while (1)
	{
		elapsed = get_time() - start;
		if(elapsed >= duration_ms)
			break;
		if(!get_simulation_state(data))
			break;
		usleep(500);
	}
}*/
void	precise_sleep(t_data *data, long duration_ms)
{
	long	start;

	start = get_time(); // Asegúrate de que devuelve milisegundos
	while (get_time() - start < duration_ms)
	{
		// 1. Comprobación de seguridad: ¿Alguien ha muerto?
		if (!get_simulation_state(data))
			break;

		// 2. Fragmento de sueño
		// Usamos un margen para no pasarnos del tiempo total
		if ((duration_ms - (get_time() - start)) > 10)
			usleep(500);
		else
			usleep(100); // Sueño más fino cuando falta poco
	}
}
