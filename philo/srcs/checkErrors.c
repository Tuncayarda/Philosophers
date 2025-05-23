/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkErrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:55:40 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/24 01:29:06 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	is_numeric(const char *s)
{
	if (!*s)
		return (0);
	if (*s == '+')
		++s;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		++s;
	}
	return (1);
}

char	*check_errors(int ac, char **av)
{
	long	num;

	if (ac != 5 && ac != 6)
		return ("Invalid number of arguments. Expected 5 or 6.");
	while (av[--ac] && ac > 0)
	{
		if (!is_numeric(av[ac]))
			return ("All arguments must be numeric.");
		num = ft_atoi(av[ac]);
		if (ac == 1 || ac == 5)
		{
			if (ac == 5 && (num < 0 || num > INT_MAX))
				return ("Meal count must be between 0 and INT_MAX.");
			if (ac == 1 && num < PHILO_COUNT_MIN)
				return ("Philosopher count too low. Must be at least 1.");
			if (ac == 1 && num > PHILO_COUNT_MAX)
				return ("Philosopher count too high. Max is 200.");
		}
		if (num < 1 || num > INT_MAX)
			return ("Argument must be a positive number less than INT_MAX.");
	}
	return (NULL);
}
