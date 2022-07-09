/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/02 11:57:15 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/22 12:00:05 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Invalid arguments.\n", 2);
		return (1);
	}
	data = ft_init_struct(argv);
	if (!data.meals || !data.number || ft_init_mutexes(&data))
		return (1);
	philo = ft_init_philo(&data);
	if (!philo || pthread_mutex_lock(&data.datamutex) || \
		ft_create_threads(&philo))
		return (1);
	pthread_mutex_unlock(&data.datamutex);
	if (ft_handle_death(&data, &philo))
	{
		ft_clear_philo(&philo, -1, data.number, data.number);
		ft_clear_data(&data);
		return (3);
	}
	ft_clear_philo(&philo, -1, data.number, data.number);
	ft_clear_data(&data);
	return (0);
}
