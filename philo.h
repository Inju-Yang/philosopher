/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 22:24:58 by inyang            #+#    #+#             */
/*   Updated: 2021/10/26 02:59:57 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5
# define FULL	6

typedef struct s_common
{
	int					philo_numbers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					philo_must_eat;
	int					philo_must_eat_flag;
	unsigned long		base_time;
	int					*fork;
	int					check_flag;
	pthread_t			*thread_id;
	pthread_t			tid_number;
	pthread_mutex_t		*mutex_id;
	pthread_mutex_t		mutex_number;
	pthread_mutex_t		print_mutex;
}						t_common;

typedef struct s_philo
{
	int					num;
	int					l_fork;
	int					r_fork;
	int					status;
	int					eat_cnt;
	unsigned long		last_eat;
	t_common			*common;
}						t_philo;

int				ft_atoi(char *str);
int				ft_isdigit(int i);

int				start_philo(t_philo *philo, t_common *common);
void			mutex_destroy(t_common *common);
void			common_init(t_common *common, int ac, char **av);
void			fill_common_info(t_common *common);
t_philo			*philo_init(t_common *common);

void			*philo_activate(void *arg);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

unsigned long	check_time(void);
void			waiting_usleep(unsigned long millisec);

void			philo_fork_down(t_philo *philo, int l_fork, int r_fork);
void			philo_get_fork(t_philo *philo,
					int l_fork, int r_fork, int philo_num);
void			philo_see_fork(t_philo *philo);

void			print_status(t_common *common,
					unsigned long time, int num, int status);
void			now_philo_is(t_common *common,
					unsigned long time, int num, char *s);

int				philo_must_eat_check(t_common *common);
int				time_to_die_check(t_philo *philo, t_common *common);

#endif
