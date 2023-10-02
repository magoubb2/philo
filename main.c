/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:04:32 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/02 16:56:41 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This function is intended for initializing mutexes (representing forks) 
// for a certain number of philosophers. It takes a pointer to an array of 
// mutexes fork and the number of philosophers nb_philo as parameters.
// Init the forks mutexes depending of nb_philo.
static void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
}

// Destroys all the mutex.
static void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philo[i].lock);
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
}

// 1. The first thing we do is check the numbers of arguments.
// 2. Then we check the parsing.
// 3. Check the condition for if there is only one philo.
// 4. Init the forks.
// 5. We start the timmer after we init the forks.
// 6. We create the threads (philos).
// 7. Then we check if there is a dead philo.
// 8. Finally we join the threads.
int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 5 || argc > 6)
		return (printf("Argument error\n"), -1);
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
	create_philos_t(&data);
	check_monitor(data.philo);
	i = 0;
	while (i < data.nb_philo)
		pthread_join(data.philo_tid[i++], NULL);
	destroy_mutex(&data);
	return (0);
}
