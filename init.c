/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:28:14 by margueriteb       #+#    #+#             */
/*   Updated: 2023/09/15 19:27:44 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(t_data *data, int nb_philo)
{
    int i;
    t_data data;

    i = 0;
    while (i < nb_philo)
    {
        pthread_mutex_init(&data->fork[i], NULL);
        i++;
    }
}