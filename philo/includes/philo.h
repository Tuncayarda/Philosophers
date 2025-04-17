/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:21:00 by tuaydin           #+#    #+#             */
/*   Updated: 2025/04/17 18:30:02 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_COUNT_MAX 200
# define PHILO_COUNT_MIN 1

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef enum	e_error_code
{
	ARGUMENT_ERROR,
	PHILO_COUNT_UNDERFLOW,
	PHILO_COUNT_OVERFLOW,
	INT_OVERFLOW
}				t_error_code;

typedef struct	s_philo
{
	
}				t_philo;

void	terminate_prog(char *msg, int exit_code);
void	handle_error(size_t error_code);
void	check_errors(int ac, char **av);
long	ft_atoi(const char *str);

#endif