/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:42:35 by made-ped          #+#    #+#             */
/*   Updated: 2026/02/25 22:17:02 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	meal_mutex;
	pthread_t		thread;
	struct s_data	*data;
	int				id;
	int				meals_eaten;
	int				left_fork;
	int				right_fork;
	long			last_meal;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;	
	pthread_mutex_t	*forks;	
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print_mutex;
	pthread_t		monitor_thread;
	t_philo			*philos;
	long			start_time;
	int				simulation_running;
}	t_data;

void	ft_control_error(int argc, char **argv);
void	ft_init_data(t_data *data, char **argv);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
void	init_philos(t_data *data);
void	assing_philo(t_philo *philo, t_data *data, int index);
void	free_data(t_data *data);
int		init_forks(t_data *data);
int		take_forks(t_philo *philo);
void	put_forks(t_philo *philo);
int		create_threads(t_data *data);
void	*philo_routine(void *arg);
int		init_simulation(t_data *data);
long	get_time(void);
int		get_simulation_state(t_data *data);
void	stop_simulation(t_data *data);
void	*monitor_routine(void *arg);
void	print_status(t_philo *philo, char *msg);
void	set_last_meal(t_philo *philo);
long	get_last_meal(t_philo *philo);
int		ft_strcmp(const char *s1, const char *s2);
void	precise_sleep(t_data *data, long duration_ms);

#endif
