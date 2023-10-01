/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:04:32 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/01 12:46:31 by mabaron-         ###   ########.fr       */
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
	int i;

	if (argc < 5 || argc > 6)
		return (printf("Argument error\n"), -1);
	// parse
	if (parse_arg(argv, &data) == -1)
		return (-1);
	if (data.nb_philo == 1)
	{
		printf("0 Philo 1 takes left fork\n");
		ft_usleep(data.time_to_die);
		printf("%d Philo 1 is dead\n", data.time_to_die);
		return (0);
	}
	init_forks(&data);
	data.start_timer = get_time();
	// create threads (philos)
	create_philos_t(&data);
	while (data.dead == 0)
	{
		check_monitor(data.philo);
	}
	// join threads
	i = 0;
	while (i < data.nb_philo)
		pthread_join(data.philo_tid[i++], NULL);
	return (0);
}
