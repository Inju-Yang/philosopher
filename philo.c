/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 22:42:43 by inyang            #+#    #+#             */
/*   Updated: 2021/10/26 20:46:35 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_common_info(t_common *common)
{
	int	i;

	common->base_time = check_time();
	common->check_flag = 0;
	common->mutex_id = malloc(sizeof(pthread_mutex_t) * common->philo_numbers);
	i = -1;
	while (++i < common->philo_numbers)
		pthread_mutex_init(&(common->mutex_id)[i], NULL);
	pthread_mutex_init(&common->print_mutex, NULL);
	common->fork = malloc(sizeof(int) * common->philo_numbers);
	memset(common->fork, 0, common->philo_numbers);
	common->thread_id = malloc(sizeof(pthread_t) * common->philo_numbers);
}

void	mutex_destroy(t_common *common)
{
	int	i;

	i = -1;
	while (++i < common->philo_numbers)
		pthread_mutex_destroy(&(common->mutex_id)[i]);
	pthread_mutex_destroy(&common->print_mutex);
}

int	start_philo(t_philo *philo, t_common *common)
{
	int	i;

	i = -1;
	while (++i < common->philo_numbers)
	{
		pthread_create(&(common->thread_id[i]),
			NULL, philo_activate, &philo[i]);
		pthread_detach(common->thread_id[i]);
		usleep(100);
	}
	while (1)
	{
		if (philo_must_eat_check(common))
			break ;
		if (time_to_die_check(philo, common))
			break ;
	}
	mutex_destroy(common);
	return (0);
}

int	main(int ac, char **av)
{
	t_common	common;
	t_philo		*philo;

	if (ac != 5 && ac != 6)
		printf("Argument error\n");
	else
	{
		common_init(&common, ac, av);
		fill_common_info(&common);
		philo = philo_init(&common);
		start_philo(philo, &common);
	}
	return (0);
}
