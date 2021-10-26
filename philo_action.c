/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:45:40 by inyang            #+#    #+#             */
/*   Updated: 2021/10/26 20:39:47 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	philo->status = THINK;
	print_status(philo->common,
		check_time() - philo->common->base_time, philo->num, philo->status);
}

void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	print_status(philo->common,
		check_time() - philo->common->base_time, philo->num, philo->status);
	philo_fork_down(philo, philo->l_fork, philo->r_fork);
	waiting_usleep(philo->common->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	if (philo->common->fork[philo->l_fork] == philo->num
		&& philo->common->fork[philo->r_fork] == philo->num)
	{
		philo->status = EAT;
		philo->last_eat = check_time();
		print_status(philo->common,
			check_time() - philo->common->base_time, philo->num, philo->status);
		philo->eat_cnt++;
	}
	waiting_usleep(philo->common->time_to_eat);
}

void	*philo_activate(void *arg)
{
	t_philo		*philo;
	t_common	*common;

	philo = (t_philo *)arg;
	common = philo->common;
	while (1)
	{
		philo_see_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (arg);
}
