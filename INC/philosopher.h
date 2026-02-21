/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:42:35 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/21 20:50:16 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct s_philo
{
	int	id;
	int	meals_eaten;
	struct	s_data	*data;
}	t_philo;

typedef struct s_data
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	must_eat;
	t_philo	*philos;
}	t_data;

void	ft_control_error(int argc, char **argv);
void	ft_init_data(t_data *data, char **argv);
long    ft_atol(const char *str);
int	ft_isdigit(int c);
void	init_philos(t_data *data);
void	assing_philo(t_philo *philo, t_data *data, int index);
void	free_data(t_data *data);

#endif
