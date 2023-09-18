/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:28:14 by margueriteb       #+#    #+#             */
/*   Updated: 2023/09/18 15:17:25 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(t_data *data)
{
    int i;
	
    i = 0;
    while (i < data->nb_philo)
    {
        pthread_mutex_init(&data->fork[i], NULL);
        i++;
    }
}