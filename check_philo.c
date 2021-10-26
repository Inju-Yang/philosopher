/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:14:52 by inyang            #+#    #+#             */
/*   Updated: 2021/10/26 17:04:34 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_die_check(t_philo *philo, t_common *common)
{
	int	i;
	unsigned long	time;

	i = -1;
	time = 0;
	while (++i < common->philo_numbers)
	{
		time = check_time();
		if (time - philo[i].last_eat >= (unsigned long)(common->time_to_die))
		{
			common->check_flag = 1;
			print_status(common, time - philo->common->base_time, i + 1, DIE);
			return (1);
		}
		if (philo[i].eat_cnt == common->philo_must_eat)
		{
			common->philo_must_eat_flag++;
			philo[i].eat_cnt++;
		}
	}
	return (0);
}

int	philo_must_eat_check(t_common *common)
{
	if (common->philo_must_eat
		&& common->philo_must_eat_flag == common->philo_numbers)
		return (1);
	else
		return (0);
}
