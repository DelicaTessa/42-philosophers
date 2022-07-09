/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 19:20:42 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/21 13:40:49 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clear_data(t_data *data)
{
	pthread_mutex_destroy(&data->datamutex);
	pthread_mutex_destroy(&data->deathmutex);
	pthread_mutex_destroy(&data->printmutex);
	pthread_mutex_destroy(&data->mealsmutex);
}

void	ft_clear_philo(t_philo **philo, int forknb, int eatnb, int philonb)
{
	int	i;

	i = 0;
	if (forknb == -1)
		forknb = (*philo)->data->number;
	ft_join_threads(philo, philonb);
	i = 0;
	while (i < eatnb)
	{
		pthread_mutex_destroy(&(*philo)[i].st_eatingmutex);
		i++;
	}
	i = 0;
	while (i < forknb)
	{
		pthread_mutex_destroy(&(*philo)[i].mutex_lfork);
		i++;
	}
	free(*philo);
}

int	*ft_parse_and_check(char **argv, int *args)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		args[i] = ft_atoi(argv[i + 1]);
		if (args[i] == -1 || args[i] != ft_atol(argv[i + 1]))
			return (NULL);
		i++;
	}
	if (args[0] == 0)
		return (NULL);
	if (argv[5] == NULL)
		args[4] = -1;
	return (args);
}
