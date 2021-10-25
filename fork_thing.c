/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_thing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:59:08 by inyang            #+#    #+#             */
/*   Updated: 2021/10/26 00:30:35 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork_down(t_philo *philo, int l_fork, int r_fork)
{
	philo->common->fork[l_fork] = -1;
	philo->common->fork[r_fork] = -1;
	pthread_mutex_unlock(&philo->common->mutex_id[l_fork]);
	pthread_mutex_unlock(&philo->common->mutex_id[r_fork]);
}

void	philo_get_fork(t_philo *philo, int l_fork, int r_fork, int philo_num)
{
	pthread_mutex_lock(&philo->common->mutex_id[l_fork]);
	pthread_mutex_lock(&philo->common->mutex_id[r_fork]);
	philo->common->fork[l_fork] = philo_num;
	philo->common->fork[r_fork] = philo_num;
	philo->status = FORK;
	print_status(philo->common,
		check_time() - philo->common->base_time, philo->num, philo->status);
}

void	philo_see_fork(t_philo *philo)
{
	if (philo->num % 2 == 0)
		usleep(300);
	philo_get_fork(philo, philo->l_fork, philo->r_fork, philo->num);
}
