/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:38:15 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/02 15:48:11 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//This function gets the time in milliseconds.
size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// This function prints the messages we want to print and the current time -
// start_timer.
void	print_message(t_state state, t_philo *philo, int id)
{
	size_t	time;
	int		dead;
	char	*s;

	time = get_time() - philo->data->start_timer;
	s = get_message(state);
	pthread_mutex_lock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->dead_lock);
	dead = !philo->data->dead;
	if (state == DEAD)
		philo->data->dead = 1;
	pthread_mutex_unlock(&philo->data->dead_lock);
	if (dead)
	{
		printf("%zu Philo %i %s\n", time, id + 1, s);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

// This function gets the time for the sleep function.
int	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep (50);
	return (0);
}

int	is_dead(t_philo *philo)
{
	size_t	current_time;
	size_t	time_must_eat;

	current_time = get_time() - philo->data->start_timer;
	time_must_eat = philo->last_meal_ms + philo->data->time_to_die;
	if (current_time > time_must_eat)
	{
		return (1);
	}
	return (0);
}

char	*get_message(t_state state)
{
	if (state == EATING)
		return ("is eating");
	if (state == THINKING)
		return ("is thinking");
	if (state == SLEEPING)
		return ("is sleeping");
	if (state == LEFT_FORK)
		return ("takes left fork");
	if (state == RIGHT_FORK)
		return ("takes right fork");
	if (state == DEAD)
		return ("is dead");
	return (NULL);
}
