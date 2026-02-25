/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funtion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:43:58 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/25 21:02:27 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/philosopher.h"

void	free_data(t_data *data)
{
	if (data->philos)
		free (data->philos);
	if (data->forks)
		free (data->forks);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
