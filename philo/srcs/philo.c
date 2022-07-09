/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 19:21:06 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/13 14:48:59 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef void	*(*t_routine)(void *);

int	ft_create_threads(t_philo **philo)
{
	int	i;

	i = 0;
	(*philo)->data->st_time = ft_gettime();
	(*philo)->data->died = 0;
	while (i < (*philo)->data->number)
	{
		if (pthread_create(&(*philo)[i].philo_thread, NULL, \
			(t_routine)ft_philo_routine, &(*philo)[i]))
		{
			ft_protect_datamutexes(philo);
			ft_clear_philo(philo, -1, i, i);
			return (1);
		}
		if (pthread_mutex_init(&(*philo)[i].st_eatingmutex, NULL))
		{
			ft_protect_datamutexes(philo);
			ft_clear_philo(philo, -1, i, i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_join_threads(t_philo **philo, int philonb)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < philonb)
	{
		if (pthread_join((*philo)[i].philo_thread, NULL) != 0)
			error++;
		i++;
	}
	if (i == philonb)
		return (0);
	return (error);
}

t_philo	*ft_init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	data->meals_eaten = 0;
	philo = malloc(data->number * sizeof (*philo));
	while (i < data->number && philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].started_eating = 0;
		if (pthread_mutex_init(&philo[i].mutex_lfork, NULL))
		{
			ft_clear_philo(&philo, i, 0, 0);
			return (NULL);
		}
		if (i != data->number - 1)
			philo[i].mutex_rfork = &philo[i + 1].mutex_lfork;
		else
			philo[i].mutex_rfork = &philo[0].mutex_lfork;
		philo[i].data = data;
		i++;
	}
	return (philo);
}

void	ft_protect_datamutexes(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->data->mealsmutex);
	(*philo)->data->meals_eaten = (*philo)->data->number;
	pthread_mutex_unlock(&(*philo)->data->mealsmutex);
	pthread_mutex_unlock(&(*philo)->data->datamutex);
}
