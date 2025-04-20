/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:21:00 by tuaydin           #+#    #+#             */
/*   Updated: 2025/04/20 03:20:10 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_COUNT_MAX 200
# define PHILO_COUNT_MIN 1

# define ARGUMENT_ERROR "ARGUMENT ERROR"
# define PHILO_COUNT_UNDERFLOW "PHILO COUNT UNDERFLOW"
# define PHILO_COUNT_OVERFLOW "PHILO COUNT OVERFLOW"
# define MEMORY_FAILURE "MEMORY ERROR"

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>


typedef struct	s_philo
{
	pthread_t	thread;
	size_t		id;
	size_t		eaten_meals;
	size_t		last_meal;
}				t_philo;

typedef	struct	s_program
{
	t_philo		*philos;
	size_t		philo_count;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	long		meals_to_finish;
	size_t		start_time;
}				t_program;


void	handle_error(char *error_msg, int exit_code);
void	check_errors(int ac, char **av);
long	ft_atoi(const char *str);
t_program	init_program(int ac, char **av);
size_t	get_current_millis(void);
void	philo_routine(void);

#endif