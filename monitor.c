/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:10:03 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/02 15:19:45 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_monitor(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_lock(&philo->lock);
		if (is_dead(&philo[i]))
		{
			if (philo->nb_of_meal == philo->data->max_eat)
			{
				pthread_mutex_unlock(&philo->lock);
				pthread_mutex_lock(&philo->data->dead_lock);
				philo->data->dead = 1;
				pthread_mutex_unlock(&philo->data->dead_lock);
				break ;
			}
			pthread_mutex_unlock(&philo->lock);
			print_message(DEAD, philo, philo->id);
			return ;
		}
		else
		{
			pthread_mutex_unlock(&philo->lock);
			return ;
		}
		i++; 
	}
}
