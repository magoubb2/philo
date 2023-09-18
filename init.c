/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:28:14 by margueriteb       #+#    #+#             */
/*   Updated: 2023/09/18 12:44:00 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(t_data *data, int nb_philo)
{
    int i;
	
    i = 0;
    while (i < nb_philo)
    {
        pthread_mutex_init(&data->fork[i], NULL);
        i++;
    }
}