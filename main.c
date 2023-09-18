/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:04:32 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/18 15:07:06 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	init_philos_t(&data);
	// join threads

	return (0);
}
