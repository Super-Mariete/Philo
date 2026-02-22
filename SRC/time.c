/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:05:00 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/22 19:18:22 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

long	get_time(void)
{
	struct	timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
