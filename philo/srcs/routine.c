/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 19:21:13 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/13 15:48:36 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(t_philo *philo)
{
	int	i;
	int	f;

	i = 0;
	pthread_mutex_lock(&philo->data->datamutex);
	pthread_mutex_unlock(&philo->data->datamutex);
	if (philo->philo_id % 2 == 0)
		ft_sleep_func(&philo, 1);
	while (!ft_check_meals_eaten(&philo) && philo->data->meals != 0
		&& !ft_check_death(&philo))
	{
		if (philo->data->number != 1)
			ft_philo_print(&philo, "%lld %d is thinking\n");
		f = ft_take_first_fork(&philo);
		ft_philo_eat(&philo, f);
		if (f > 0)
			pthread_mutex_unlock((philo)->mutex_rfork);
		if (philo->data->meals > 0 && (i + 1) == philo->data->meals && f == 2)
			ft_incr_meals_eaten(&philo);
		ft_philo_sleep(&philo, f);
		i++;
		while (!ft_check_death(&philo) && (philo->data->number == 1 && i))
			usleep(150);
	}
	return (philo);
}

void	ft_sleep_func(t_philo **philo, long long msec)
{
	long long	timestamp;

	timestamp = ft_gettime();
	while (!ft_check_death(philo) && !ft_check_meals_eaten(philo)
		&& ft_gettime() - timestamp < msec)
		usleep(150);
}

long long	ft_gettime(void)
{
	t_timeval		now;
	unsigned long	time;

	if (gettimeofday(&now, NULL) != 0)
	{
		ft_putstr_fd("Error in ft_gettime\n", 2);
		return (-1);
	}
	time = ((now.tv_sec * 1000) + (now.tv_usec / 1000));
	return (time);
}
