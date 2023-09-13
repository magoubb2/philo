/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:38 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/12 18:01:06 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Check for only digits.

// Check for number of philo.

// Check for time.

// Check for max_eat

static int check_int(char *s)
{
    
}

static int	parse_arg(char **argv, t_data *data)
{
	int i;
    
    i = 0;
	// ./philo nb_philo die eat sleep
    while (argv[i])
    {		
        // check func
		check_int(argv[i]);

		// assign t_data variables
        i++;
    }
}

int	parse(t_data *data, int argc, char **argv)
{
	if (parse_arg(argv, data) == -1)
		return (-1);
}