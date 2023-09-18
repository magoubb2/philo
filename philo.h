/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:09:25 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/18 12:45:06 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

typedef struct s_philo
{
	int l_fork;
    int r_fork;
    int last_meal_ms;
    int nb_of_meal;
}   t_philo;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
    int				time_to_sleep;
	int				nb_philo;
	int				max_eat; //for 5em arg
	t_philo			philo[200]; // philo data
	pthread_t		philo_t[200]; // philo threads
	pthread_mutex_t	fork[200]; // forks (tableau de mutex) represent les fourchettes des philosophes
}   t_data;

// parsing
int		parse_arg(char **argv, t_data *data);
// atoi
int		ft_atoi(const char *str);
// This function is intended for initializing mutexes (representing forks) 
// for a certain number of philosophers. It takes a pointer to an array of 
//mutexes fork and the number of philosophers nb_philo as parameters.
void init_forks(t_data *data, int nb_philo);



#endif