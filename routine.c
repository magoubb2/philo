/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:04 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/19 20:33:59 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_routine(void *data)
{
	
	//eat
	//sleep
	//think
	//if (dead == 1)
	//	break ;
	t_philo *philo;
	
	philo = data;
	sleep(1);
	printf("test philo%i\n", philo->id);
	return (NULL);
}

// create the philos threads
void create_philos_t(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo_tid[i], NULL, &philos_routine, &data->philo[i]);
		i++;
	}
}