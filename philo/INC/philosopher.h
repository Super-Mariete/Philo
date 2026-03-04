/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:42:35 by made-ped          #+#    #+#             */
/*   Updated: 2026/03/04 20:44:15 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	t_data				*data;
	int					id;
	int					left_fork;
	int					rigth_fork;
	long				last_meal;
	int					meals_eaten;
}						t_philo;

struct					s_data
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		data_mutex;
	int					nb_philo;
	long				time_die;
	long				time_eat;
	long				time_sleep;
	int					must_eat;
	int					all_ate;
	int					someone_dead;
	long				start_time;
	t_philo				*philos;
};

int						init_data(t_data *data, int argc, char **argv);
long					get_time(void);
void					precise_usleep(long time, t_data *data);
void					print_status(t_data *data, int id, char *str);
int						ft_atoi(const char *str);
void					*routine(void *arg);
void					*monitor(void *arg);
int						clean(t_data *data, char *msg);
int						validate_args(int argc, char **argv);
int						should_stop(t_data *data);

#endif
