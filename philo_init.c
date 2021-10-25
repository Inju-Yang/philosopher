/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:46:35 by inyang            #+#    #+#             */
/*   Updated: 2021/10/26 02:57:48 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_init(t_common *common)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * common->philo_numbers);
	while (++i < common->philo_numbers)
	{
		philo[i].num = i + 1;
		philo[i].last_eat = check_time();
		if (i == 0)
			philo[i].l_fork = common->philo_numbers - 1;
		else
			philo[i].l_fork = i - 1;
		philo[i].r_fork = i;
		philo[i].eat_cnt = 0;
		philo[i].status = 0;
		philo[i].common = common;
	}
	return (philo);
}

void	common_init(t_common *common, int ac, char **av)
{
	common->philo_numbers = ft_atoi(av[1]);
	common->time_to_die = ft_atoi(av[2]);
	common->time_to_eat = ft_atoi(av[3]);
	common->time_to_sleep = ft_atoi(av[4]);
	common-> philo_must_eat = 0;
	common->philo_must_eat_flag = 0;
	if (ac == 6)
		common->philo_must_eat = ft_atoi(av[5]);
}
