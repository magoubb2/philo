/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:10:03 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/26 14:45:31 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_monitor(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		if (philo->dead)
		{
			
			philo->data->game_over = 1;
		}
		i++; 
	}
}