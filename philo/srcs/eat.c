/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 19:20:50 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/13 14:54:58 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_meals_eaten(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->data->mealsmutex);
	if ((*philo)->data->meals_eaten == (*philo)->data->number)
	{
		pthread_mutex_unlock(&(*philo)->data->mealsmutex);
		return (1);
	}
	pthread_mutex_unlock(&(*philo)->data->mealsmutex);
	return (0);
}

int	ft_check_eating_time(t_philo **philo, int i, int id)
{
	if (i == 0)
	{
		pthread_mutex_lock(&(*philo)->st_eatingmutex);
		(*philo)->started_eating = (ft_gettime() - (*philo)->data->st_time);
		pthread_mutex_unlock(&(*philo)->st_eatingmutex);
	}
	if (i == 1)
	{
		pthread_mutex_lock(&(*philo)[id].st_eatingmutex);
		if ((ft_gettime() - (*philo)->data->st_time)
			- (*philo)[id].started_eating >= (*philo)->data->t_to_die)
		{
			pthread_mutex_unlock(&(*philo)[id].st_eatingmutex);
			return (1);
		}
		pthread_mutex_unlock(&(*philo)[id].st_eatingmutex);
	}
	return (0);
}

void	ft_incr_meals_eaten(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->data->mealsmutex);
	(*philo)->data->meals_eaten++;
	pthread_mutex_unlock(&(*philo)->data->mealsmutex);
}

int	ft_take_first_fork(t_philo **philo)
{
	int	f2;

	f2 = 0;
	if (!ft_check_death(philo) && !ft_check_meals_eaten(philo))
	{
		pthread_mutex_lock(&(*philo)->mutex_lfork);
		f2 += 1;
		if ((*philo)->data->number != 1)
		{
			pthread_mutex_lock((*philo)->mutex_rfork);
			f2 += 1;
		}
		ft_philo_print(philo, "%lld %d has taken a fork\n");
	}
	return (f2);
}

void	ft_philo_eat(t_philo **philo, int fork)
{
	if (fork == 2)
	{
		ft_check_eating_time(philo, 0, 0);
		ft_philo_print(philo, "%lld %d has taken a fork\n");
		ft_philo_print(philo, "%lld %d is eating\n");
		ft_sleep_func(philo, (*philo)->data->t_to_eat);
		pthread_mutex_unlock(&(*philo)->mutex_lfork);
	}
}
