/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:09:25 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/03 13:32:34 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	size_t			last_meal_ms;
	int				nb_of_meal;
	pthread_mutex_t	lock;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_philo;
	size_t			start_timer;
	int				max_eat;
	int				dead;
	t_philo			philo[200];
	pthread_t		philo_tid[200];
	pthread_mutex_t	fork[200];
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
}	t_data;

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	RIGHT_FORK,
	LEFT_FORK,
}	t_state;

// parsing

int		parse_arg(char **argv, t_data *data);

// parsing_utils

int		ft_isdigit(char *str);
int		ft_atoi(const char *str);

// routine

void	create_philos_t(t_data *data);

// routine_utils

size_t	get_time(void);
char	*get_message(t_state state);
void	print_message(t_state state, t_philo *philo, int id);
int		ft_usleep(size_t ms);
int		is_dead(t_philo *philo);

// monitor

void	check_monitor(t_philo *philo);

#endif