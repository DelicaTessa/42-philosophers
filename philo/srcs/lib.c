/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/02 11:44:50 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/02 11:53:39 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoi(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (nb);
}

long int	ft_atol(char *str)
{
	long int		i;
	long int		nb;

	i = 0;
	nb = 0;
	if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0' || i > 10)
		return (-1);
	return (nb);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	index = 0;
	if (s == NULL)
		return ;
	while (s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}
