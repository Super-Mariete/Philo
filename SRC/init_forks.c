/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:17:31 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/21 21:32:58 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../INC/philosopher.h"

void	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(int) * data->nb_philo);
	if (!data->forks)
	{
		write(2, "Error malloc forks\n", 19);
		free_data(data);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < data->nb_philo)
	{
		data->forks[i] = 0;
		printf("Fork %d iniciado\n", i);
		i++;
	}
}
