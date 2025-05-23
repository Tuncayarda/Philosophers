/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 04:52:09 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/24 01:17:50 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_COUNT_MAX 200
# define PHILO_COUNT_MIN 1

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_program	t_program;
typedef struct s_philo		t_philo;

struct s_philo
{
	pthread_t		thread;
	size_t			id;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	long			meals_to_finish;
	long			eaten_meals;
	bool			alive;
	bool			must_eat;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_program		*prog;
};

struct s_program
{
	t_philo			*philos;
	size_t			philo_count;
	size_t			start_time;
	bool			finished;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
};

long		ft_atoi(const char *str);
size_t		get_current_millis(void);
void		ft_usleep(size_t mls);

char		*check_errors(int ac, char **av);
char		*init_program(t_program **prog_ptr, int ac, char **av);
char		*born_philos(t_program *prog);
void		set_program_free(t_program *program);

void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_print(t_philo *philo, char *msg);
void		routine_check(t_program *prog);

#endif