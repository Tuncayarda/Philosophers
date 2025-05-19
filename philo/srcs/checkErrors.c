/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkErrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:55:40 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/19 20:52:22 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*check_errors(int ac, char **av)
{
	long	num;

	if (ac != 5 && ac != 6)
		return (ARGUMENT_ERROR);
	while (av[--ac] && ac > 0)
	{
		num = ft_atoi(av[ac]);
		if (ac == 1 || ac == 5)
		{
			if (ac == 5 && (num < 0 || num > INT_MAX))
				return (ARGUMENT_ERROR);
			if (ac == 1 && num < PHILO_COUNT_MIN)
				return (PHILO_COUNT_UNDERFLOW);
			if (ac == 1 && num > PHILO_COUNT_MAX)
				return (PHILO_COUNT_OVERFLOW);
		}
		if (num < 1 || num > INT_MAX)
			return (ARGUMENT_ERROR);
	}
	return (NULL);
}
