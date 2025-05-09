/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkErrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:55:40 by tuaydin           #+#    #+#             */
/*   Updated: 2025/04/20 02:40:34 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_errors(int ac, char **av)
{
	long	num;
	
	if (ac != 5 && ac != 6)
		handle_error(ARGUMENT_ERROR, 1);
	while (av[--ac] && ac > 0)
	{
		num = ft_atoi(av[ac]);
		if (ac == 1 || ac == 5)
		{
			if (ac == 5 && (num < 0 || num > INT_MAX))
				handle_error(ARGUMENT_ERROR, 1);
			if (ac == 1 && num < PHILO_COUNT_MIN)
				handle_error(PHILO_COUNT_UNDERFLOW, 1);
			if (ac == 1 && num > PHILO_COUNT_MAX)
				handle_error(PHILO_COUNT_OVERFLOW, 1);
		}
		if (num < 1 || num > INT_MAX)
			handle_error(ARGUMENT_ERROR, 1);
	}
}
