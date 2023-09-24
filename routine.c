/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:04 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/24 14:58:07 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This function prints the message for when a philo is taking a left frok, a
// right fork and when it's eating.
static void	philo_eat(t_philo *philo)
{
	// take forks
	pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
	print_message("philo, takes left fork", philo, philo->id);
	pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
	print_message("philo, takes right fork", philo, philo->id);
	// eat for time_to_eat and print
	print_message("philo is eating", philo, philo->id);
	philo->nb_of_meal++;
	// unlock forks
	pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
}

// This function prints the message for when a philo is sleeping and it sleeps
// for the length of time we ask it to sleep.
static void philo_sleep(t_philo *philo)
{
	print_message("philo, is sleeping", philo, philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

// This function prints the messages for when a philo is thinking.
static void	philo_think(t_philo *philo)
{
	print_message("philo is thinking", philo, philo->id);
}

// Philo's routine
void	*philos_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep (100);
	while (1)
	{
		//if (max_eat)
		if (philo->nb_of_meal == philo->data->max_eat)
			break ;
		//eat
		philo_eat(philo);
		//sleep
		philo_sleep(philo);
		//think
		philo_think(philo);
		//if (philo = dead)
	}
	//if (dead == 1)
	//	break ;
	
	return (NULL);
}

// create the philos threads
void create_philos_t(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo_tid[i], NULL, (void *)&philos_routine, &data->philo[i]);
		i++;
	}
}