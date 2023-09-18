/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:04 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/18 15:22:40 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_routine(t_philo *philo)
{
	//eat
	//sleep
	//think
	printf("test philo%i\n", philo->id);
}

void create_philos_t(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philo_t[i], NULL, (void *)&philos_routine, &data->philo[i]);
		i++;
	}
}