/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:28:14 by margueriteb       #+#    #+#             */
/*   Updated: 2023/09/15 17:08:26 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_fork(pthread_mutex_t	*fork, int nb_philo)
{
    int i;

    i = 0;
    while (i < nb_philo)
    {
        pthread_mutex_init(&fork[i], NULL);
        i++;
    }
}