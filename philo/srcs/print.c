/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/02 11:51:45 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/13 14:37:47 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_print(t_philo **philo, char *str)
{
	pthread_mutex_lock(&(*philo)->data->printmutex);
	if (!ft_check_meals_eaten(philo) && !ft_check_death(philo))
	{
		printf(str, ft_gettime() - (*philo)->data->st_time, (*philo)->philo_id);
	}
	pthread_mutex_unlock(&(*philo)->data->printmutex);
}

void	ft_philo_sleep(t_philo **philo, int nb)
{
	if (nb == 2)
	{
		ft_philo_print(philo, "%lld %d is sleeping\n");
		ft_sleep_func(philo, (*philo)->data->t_to_sleep);
	}
}
