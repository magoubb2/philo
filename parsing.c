/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:38 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/13 16:04:29 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Check for only digits.

// Check for number of philo.

// Check for time.

// Check for max_eat

static int check_int(char **argv)
{
    int i;

    i = 1;
    while (argv[i])
    {
        if (!(ft_isdigit(argv[i])))
            return (-1);
        i++;
    }
    return (0);
}

static int	parse_arg(char **argv, t_data *data)
{
	// ./philo nb_philo die eat sleep	
    // check func
	// assign t_data variables
    if ((check_int(argv) == -1))
        printf("Argument digit error\n");
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->nb_philo = ft_atoi(argv[1]);
    if (data->nb_philo > 200 || data->nb_philo == 0)
    {
        printf("Error number of philosopher\n");
        return (-1);
    }
    return (0);
}

int	parse(t_data *data, int argc, char **argv)
{
    (void)argc;
	if (parse_arg(argv, data) == -1)
		return (-1);
    return (0);
}