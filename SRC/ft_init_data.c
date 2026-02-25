/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:54:44 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/25 22:39:06 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"

int	ft_init_data(t_data *data, char **argv)
{
	int		i;
	long	value;

	i = 1;
	data->must_eat = -1;
	while (argv[i] != NULL)
	{
		value = ft_atol (argv[i]);
		if (value <= 0 || value >= INT_MAX)
			return (0);
		if (i == 1)
			data->nb_philo = (int)value;
		else if (i == 2)
			data->time_die = (int)value;
		else if (i == 3)
			data->time_eat = (int)value;
		else if (i == 4)
			data->time_sleep = (int)value;
		else if (i == 5)
			data->must_eat = (int)value;
		i++;
	}
	return (1);
}
