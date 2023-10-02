/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:04 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/02 14:47:27 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This function prints the message for when a philo is taking a left frok, a
// right fork and when it's eating.
static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
	print_message(LEFT_FORK, philo, philo->id);
	pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
	print_message(RIGHT_FORK, philo, philo->id);
	print_message(EATING, philo, philo->id);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal_ms = get_time() - philo->data->start_timer;
	philo->nb_of_meal++;
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
}

// This function prints the message for when a philo is sleeping and it sleeps
// for the length of time we ask it to sleep.
static void	philo_sleep(t_philo *philo)
{
	print_message(SLEEPING, philo, philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

// This function prints the messages for when a philo is thinking.
static void	philo_think(t_philo *philo)
{
	print_message(THINKING, philo, philo->id);
}

// Philo's routine, if there is a 5th argument, once the nb_of_meals is
// == to the number of max_eat, the program breaks and stops.
void	*philos_routine(t_philo *philo)
{
	int	dead;
	
	if (philo->id % 2 == 0)
		usleep (100);
	philo->last_meal_ms = get_time() - philo->data->start_timer;
	pthread_mutex_lock(&philo->data->dead_lock);
	dead = philo->data->dead;
	pthread_mutex_unlock(&philo->data->dead_lock);
	while (!dead)
	{
		if (philo->nb_of_meal == philo->data->max_eat)
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);	
		pthread_mutex_lock(&philo->data->dead_lock);
		dead = philo->data->dead;
		pthread_mutex_unlock(&philo->data->dead_lock);
	}
	return (NULL);
}

// create the philos threads
void	create_philos_t(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo_tid[i], NULL, \
			(void *)&philos_routine, &data->philo[i]);
		i++;
	}
}
