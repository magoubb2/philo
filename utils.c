/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:38:15 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/24 15:27:07 by mabaron-         ###   ########.fr       */
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
	time = get_time() - philo->data->start_timer;
	printf("%lu Philo %i %s\n", time, id + 1, s);
	pthread_mutex_unlock(&philo->data->write_lock);
}

// This function gets the time for the sleep function.
int	ft_usleep(size_t ms)
{
	size_t start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep (500);
	return (0);
}