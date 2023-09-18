/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:04:32 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/18 15:20:59 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This function is intended for initializing mutexes (representing forks) 
// for a certain number of philosophers. It takes a pointer to an array of 
//mutexes fork and the number of philosophers nb_philo as parameters.
static void	init_forks(t_data *data)
{
    int i;
	
    i = 0;
    while (i < data->nb_philo)
    {
        pthread_mutex_init(&data->fork[i], NULL);
        i++;
    }
}

// ./philo nb_philo die eat sleep
int main(int argc, char **argv)
{
	t_data data;

	if (argc < 5 || argc > 6)
		return (printf("Argument error\n"), -1);
	// parse
	if (parse_arg(argv, &data) == -1)
		return (-1);
	init_forks(&data);
	// create threads (philos)
	create_philos_t(&data);
	// join threads

	return (0);
}
