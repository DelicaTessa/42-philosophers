/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   death.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/02 11:49:59 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/13 14:43:30 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->data->deathmutex);
	if ((*philo)->data->died == 1)
	{
		pthread_mutex_unlock(&(*philo)->data->deathmutex);
		return (1);
	}
	pthread_mutex_unlock(&(*philo)->data->deathmutex);
	return (0);
}

int	ft_handle_death(t_data *data, t_philo **philo)
{
	int	i;

	while (!ft_check_death(philo) && \
		!ft_check_meals_eaten(philo) && data->meals != 0)
	{
		i = 0;
		while (i < data->number && !ft_check_death(philo) && \
			!ft_check_meals_eaten(philo))
		{
			if (ft_check_eating_time(philo, 1, i))
			{
				pthread_mutex_lock(&(*philo)->data->printmutex);
				printf("%lld %d died\n", ft_gettime()
					- (*philo)->data->st_time, (*philo)[i].philo_id);
				pthread_mutex_unlock(&(*philo)->data->printmutex);
				if (pthread_mutex_lock(&data->deathmutex))
					return (-1);
				data->died = 1;
				pthread_mutex_unlock(&data->deathmutex);
			}
			i++;
		}
		usleep(1000);
	}
	return (0);
}
