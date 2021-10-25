/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:44:47 by inyang            #+#    #+#             */
/*   Updated: 2021/10/25 21:28:25 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	waiting_usleep(unsigned long millisec)
{
	unsigned long	obj_time;

	obj_time = millisec + check_time();
	while (obj_time > check_time())
		usleep(100);
}

unsigned long	check_time(void)
{
	struct timeval	tv;
	unsigned long	time;

	gettimeofday(&tv, NULL);
	time = (unsigned long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (-1);
}

int	ft_atoi(char *str)
{
	int	result;
	int	count;
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) < 0)
			return (-1);
	}
	result = 0;
	count = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		count++;
	}
	return (result);
}
