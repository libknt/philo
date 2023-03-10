/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:12:03 by keys              #+#    #+#             */
/*   Updated: 2023/01/19 12:15:18 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define FORK "%lu %d has taken a fork\n"
# define EAT "%lu %d is eating\n"
# define SLEEP "%lu %d is sleeping\n"
# define THINK "%lu %d is thinking\n"
# define DIE "%lu %d died\n"

typedef struct s_philo
{
	int				id;
	int				index;
	struct s_data	*data;
	bool			finish;
	pthread_mutex_t	fork1;
	pthread_mutex_t	*fork2;
}					t_philo;

typedef struct s_data
{
	bool			is_meals;
	size_t			philosophers_num;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start;
	size_t			last_eat_time[200];
	t_philo			philo[200];
	pthread_t		thread[200];
	size_t			number_of_meals[200];
	bool			end[200];
	pthread_mutex_t	print;
	pthread_mutex_t	last_eat_mutex[200];
	pthread_mutex_t	stop[200];
}					t_data;

int					ft_checks(int argc, char **argv);
int					ft_error_print(char *mes);

int					ft_make_data(t_data *data, int argc, char **argv);
int					ft_make_mutex(t_data *data);
int					ft_make_thread(t_data *data);

int					ft_eat(t_philo *philo, t_data *data);
int					ft_fork(t_philo *philo);
int					ft_mutex_unlock(pthread_mutex_t *mutex1,
						pthread_mutex_t *mutex2, int flag);
void				*philosophers(void *arg);
int					ft_sleep(t_philo *philo);
int					ft_think(t_philo *philo);
int					message(char *mes, t_philo *philo);
bool				someone_dead(t_philo *philo);
bool				thread_stop(t_data *data);

void				*death_watch(void *arg);

long				ft_atol(const char *nptr);
int					ft_isdigit(int c);
int					ft_isspace(int c);
size_t				get_time(void);

#endif
