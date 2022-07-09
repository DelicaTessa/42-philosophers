/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 19:20:58 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/13 14:40:11 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	ft_init_struct(char **argv)
{
	t_data	data;

	if (ft_parse_and_check(argv, (int *)&data) == NULL)
	{
		ft_putstr_fd("Invalid arguments. ", 2);
		ft_putstr_fd("Put 4 or 5 arguments(positive ints).\n", 2);
		data.meals = 0;
	}
	return (data);
}

int	ft_init_mutexes(t_data *data)
{
	pthread_mutex_init(&data->datamutex, NULL);
	if (pthread_mutex_init(&data->deathmutex, NULL))
	{
		pthread_mutex_destroy(&data->datamutex);
		return (1);
	}
	else if (pthread_mutex_init(&data->mealsmutex, NULL))
	{
		pthread_mutex_destroy(&data->datamutex);
		pthread_mutex_destroy(&data->deathmutex);
		return (1);
	}
	else if (pthread_mutex_init(&data->printmutex, NULL))
	{
		pthread_mutex_destroy(&data->datamutex);
		pthread_mutex_destroy(&data->deathmutex);
		pthread_mutex_destroy(&data->mealsmutex);
		return (1);
	}
	return (0);
}
