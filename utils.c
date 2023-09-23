/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:38:15 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/23 13:35:13 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void print_message(char *s, t_philo *philo, int id)
{
	size_t time;
	
	time = get_time() - philo->data->start_timer;
	// printf("time : %lu\n", time);
	// printf("start_timer: %lu\n", philo->data->start_timer);

	printf("%lu %i %s\n", time, id + 1, s);
	
	usleep(2000);
}