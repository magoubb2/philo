/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:38:15 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/27 17:22:20 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

//This function gets the time in milliseconds.
size_t	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// This function prints the messages we want to print and the current time -
// start_timer.
void print_message(char *s, t_philo *philo, int id)
{
	size_t time;

	pthread_mutex_lock(&philo->data->write_lock);
	if (!philo->data->dead)
	{
		time = get_time() - philo->data->start_timer;
		printf("%zu Philo %i %s\n", time, id + 1, s);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

// This function gets the time for the sleep function.
int	ft_usleep(size_t ms)
{
	size_t start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep (50);
	return (0);
}

int	is_dead(t_philo *philo)
{
	size_t time_since_last_meal;
	size_t current_time;
	size_t time_must_eat;


	current_time = get_time() - philo->data->start_timer;
	time_since_last_meal = current_time - philo->last_meal_ms;
	time_must_eat = philo->last_meal_ms + philo->data->time_to_die;
	// printf("DEBUG philo[%d]->last_meal_ms-> {%zu}\n",philo->id, philo->last_meal_ms);
	// printf("DEBUG current_time-> {%zu}\n",  current_time);
	// printf("DEBUG time_must_eat-> {%zu}\n",  time_must_eat);
	if (current_time > time_must_eat)
		return (1);
	// if ((size_t)philo->data->time_to_die < time_since_last_meal)
	// 	return (1);
	return (0);
}