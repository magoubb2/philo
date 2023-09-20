/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:04 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/20 17:04:50 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_philo *philo)
{
	// take forks
	pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
	printf("philo%i, takes left fork%i\n", philo->id, philo->l_fork);
	pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
	printf("philo%i, takes right fork%i\n", philo->id, philo->r_fork);
	// eat for time_to_eat and print
	printf("philo%i is eating\n", philo->id);
	philo->nb_of_meal++;
	// unlock forks
	pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
}

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
		//think
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