/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:10:03 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/01 14:52:07 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_monitor(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		if (is_dead(&philo[i]))
		{
			if (philo->nb_of_meal == philo->data->max_eat)
			{
				philo->data->dead = 1;
				break ;
			}
			print_message("is dead", philo, philo->id);
			philo->data->dead = 1;
			return ;
		}
		else
			return ;
		i++; 
	}
}
