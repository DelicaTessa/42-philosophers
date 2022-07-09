/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 19:20:29 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/13 14:55:07 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

typedef struct s_data
{
	int				number;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				meals;
	long long		st_time;
	pthread_mutex_t	datamutex;
	pthread_mutex_t	mealsmutex;
	int				meals_eaten;
	pthread_mutex_t	deathmutex;
	int				died;
	pthread_mutex_t	printmutex;
}				t_data;

typedef struct s_philo
{
	int				philo_id;
	pthread_mutex_t	st_eatingmutex;
	long long int	started_eating;
	pthread_t		philo_thread;
	pthread_mutex_t	mutex_lfork;
	pthread_mutex_t	*mutex_rfork;
	t_data			*data;
}					t_philo;

int			ft_check_death(t_philo **philo);
int			ft_handle_death(t_data *data, t_philo **philo);

void		ft_philo_eat(t_philo **philo, int fork);
void		ft_incr_meals_eaten(t_philo **philo);
int			ft_check_meals_eaten(t_philo **philo);
int			ft_check_eating_time(t_philo **philo, int i, int id);
int			ft_take_first_fork(t_philo **philo);

void		ft_philo_print(t_philo **philo, char *str);
void		ft_philo_sleep(t_philo **philo, int nb);

void		*ft_philo_routine(t_philo *philo);
void		ft_sleep_func(t_philo **philo, long long msec);
long long	ft_gettime(void);

t_philo		*ft_init_philo(t_data *data);
int			ft_create_threads(t_philo **philo);
int			ft_join_threads(t_philo **philo, int philonb);
void		ft_protect_datamutexes(t_philo **philo);

void		ft_clear_data(t_data *data);
void		ft_clear_philo(t_philo **philo, int forknb, int eatnb, int philonb);
int			*ft_parse_and_check(char **argv, int *args);

t_data		ft_init_struct(char **argv);
int			ft_init_mutexes(t_data *data);

void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_atoi(char *str);
long int	ft_atol(char *str);

#endif
