/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:38 by mabaron-          #+#    #+#             */
/*   Updated: 2023/09/13 18:58:14 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_isdigit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (-1);
}

static int	ft_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	else
	{
		return (0);
	}
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str == NULL)
		return (0);
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

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

int	parse_arg(char **argv, t_data *data)
{
    if ((check_int(argv) == -1))
    {
        printf("Argument error\n");
        return (-1);
    }
    data->nb_philo = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
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
