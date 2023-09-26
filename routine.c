/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:04 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/26 14:46:30 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

// This function prints the message for when a philo is taking a left frok, a
// right fork and when it's eating.
static void	philo_eat(t_philo *philo)
{
	// take forks
	pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
	print_message("takes left fork", philo, philo->id, 0);
	philo->last_meal_ms = get_time();
	pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
	print_message("takes right fork", philo, philo->id, 0);
	// eat for time_to_eat and print
	print_message("is eating", philo, philo->id, 0);
	philo->nb_of_meal++;
	// unlock forks
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
}

// This function prints the message for when a philo is sleeping and it sleeps
// for the length of time we ask it to sleep.
static void philo_sleep(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id, 0);
	ft_usleep(philo->data->time_to_sleep);
}

// This function prints the messages for when a philo is thinking.
static void	philo_think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id, 0);
}

// Philo's routine, if there is a 5th argument, once the nb_of_meals is
// == to the number of max_eat, the program breaks and stops.
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
		if (is_dead(philo))
			return (NULL);
		//sleep
		philo_sleep(philo);
		if (is_dead(philo))
			return (NULL);
		//think
		philo_think(philo);
		if (is_dead(philo))
		{
			print_message("is dead", philo, philo->id, 1);
			return (NULL);
		}
		//if (philo = dead)
		//philo->data->time_to_die = check_dead(philo);
		// if (philo->data->time_to_die <= 0)
		// {
		// 	print_message("died", philo, philo->id);
		// 	break ;
		// }
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