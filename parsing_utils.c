/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:42:44 by margueriteb       #+#    #+#             */
/*   Updated: 2023/09/13 15:54:53 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(char *str)
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

int	ft_atoi(const char *str)
{
	int	n;
	int	res;
	int	i;

	n = 1;
	res = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] != '\t' && str[i] != '\n' \
     && str[i] != '\v' && str[i] != '\f' && str[i] != '\r' && str[i] != ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (n * res);
}
