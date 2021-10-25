/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:20:51 by inyang            #+#    #+#             */
/*   Updated: 2021/10/25 21:28:13 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	now_philo_is(t_common *common, unsigned long time, int num, char *s)
{
	pthread_mutex_lock(&common->print_mutex);
	printf("%lu ms philo %d %s\n", time, num, s);
	pthread_mutex_unlock(&common->print_mutex);
}

void	print_status(t_common *common, unsigned long time, int num, int status)
{
	if (common->check_flag && status == DIE)
		now_philo_is(common, time, num, "died");
	else if (!common->check_flag && status == FORK)
		now_philo_is(common, time, num, "has taken a fork");
	else if (!common->check_flag && status == EAT)
		now_philo_is(common, time, num, "is eating");
	else if (!common->check_flag && status == SLEEP)
		now_philo_is(common, time, num, "is sleeping");
	else if (!common->check_flag && status == THINK)
		now_philo_is(common, time, num, "is thinking");
}
