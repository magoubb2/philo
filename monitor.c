/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:10:03 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/02 17:29:35 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// In this function we check if the condition in the "is_dead"
void	check_monitor(t_philo *philos)
{
	int		i;
	t_philo	*ptr;

	i = 0;
	while (i < philos->data->nb_philo)
	{
		ptr = &philos[i++];
		pthread_mutex_lock(&ptr->lock);
		if (is_dead(ptr))
		{
			if (ptr->nb_of_meal == ptr->data->max_eat)
			{
				pthread_mutex_unlock(&ptr->lock);
				pthread_mutex_lock(&ptr->data->dead_lock);
				ptr->data->dead = 1;
				pthread_mutex_unlock(&ptr->data->dead_lock);
				return ;
			}
			pthread_mutex_unlock(&ptr->lock);
			print_message(DEAD, ptr, ptr->id);
			return ;
		}
		pthread_mutex_unlock(&ptr->lock);
		i %= ptr->data->nb_philo;
	}
}
