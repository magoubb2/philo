/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:09:25 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/12 17:34:20 by margueriteb      ###   ########.fr       */
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
	int 	time_to_die;
	int 	time_to_eat;
    int 	time_to_sleep;
    int 	time_to_think;
	int		max_eat; //for 5em arg
	t_philo		philo[1000];
	pthread_t	philo[1000];
}   t_data;

int	parse(t_data *data, int argc, char **argv);

#endif