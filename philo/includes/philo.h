/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:21:00 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/19 20:48:08 by tuaydin          ###   ########.fr       */
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
# define THREAD_FAILURE "THREAD ERROR"
# define GET_TIME_OF_DAY_ERROR "GET_TIME_OF_DAY_ERROR"

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_program	t_program;
typedef struct s_philo		t_philo;

struct						s_philo
{
	pthread_t				thread;
	size_t					id;
	size_t					eaten_meals;
	size_t					last_meal;
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	long					meals_to_finish;
	bool					alive;
	bool					must_eat;
	pthread_mutex_t			*l_fork;
	pthread_mutex_t			*r_fork;
	struct s_program		*prog;
};

struct						s_program
{
	t_philo					*philos;
	size_t					philo_count;
	size_t					start_time;
	size_t					thread_count;
	int						philo_status;
	bool					finished;
	pthread_mutex_t			*forks;
	pthread_mutex_t			prog_mutex;
	pthread_mutex_t			print_mutex;
	pthread_mutex_t			state_mutex;
};

char						*check_errors(int ac, char **av);
long						ft_atoi(const char *str);
char						*init_program(t_program **prog_ptr, int ac,
								char **av);
size_t						get_current_millis(void);
void						ft_usleep(size_t mls);
void						*philo_routine(void *arg);
char						*born_philos(t_program *prog);
void						philo_eat(t_philo *philo);
void						philo_print(t_philo *philo, char *msg);
void						philo_sleep(t_philo *philo);
void						routine_check(t_program *prog);
void						set_program_free(t_program *program);

#endif