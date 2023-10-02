/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:38 by mabaron-          #+#    #+#             */
/*   Updated: 2023/10/02 16:53:57 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Check if digits.
static int	check_int(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!(ft_isdigit(argv[i])))
			return (-1);
		i++;
	}
	return (0);
}

// Responsible for initializing the basic data for each
// philosopher, including their identifier, the forks to 
// their left and right, as well as meal-related data.
static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->nb_philo;
		data->philo[i].last_meal_ms = 0;
		data->philo[i].nb_of_meal = 0;
		data->philo[i].data = data;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		i++;
	}
}

// Parsing
// 1. Check if the argv are only digits
// 2. Init the args.
// 3. Inits the the basic data for each philos.
// 4. Init the mutex.
// 5. Check if the number of philo is between 1 and 200.
// 6. if there is a 5th arg its initialized
int	parse_arg(char **argv, t_data *data)
{
	if ((check_int(argv) == -1))
	{
		printf("Argument error\n");
		return (-1);
	}
	data->nb_philo = ft_atoi(argv[1]);
	init_philos(data);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	if (data->nb_philo > 200 || data->nb_philo == 0)
	{
		printf("Number of philosopher error\n");
		return (-1);
	}
	if (argv[5])
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	return (0);
}
