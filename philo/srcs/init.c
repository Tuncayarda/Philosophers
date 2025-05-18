/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:29:43 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/18 08:32:05 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*init_mutexes(t_program *prog)
{
	size_t			i;
	pthread_mutex_t	*mtxs;

	i = 0;
	mtxs = malloc(sizeof(pthread_mutex_t) * prog->philo_count);
	if (mtxs == NULL)
		return (NULL);
	while (i < prog->philo_count)
	{
		pthread_mutex_init(&mtxs[i], NULL);
		i++;
	}
	return (mtxs);
}

static void	assign_forks(t_program *prog, t_philo *philo)
{
	if (!prog->forks)
		return ;
	if (philo->id % 2 == 0)
	{
		philo->r_fork = &prog->forks[philo->id];
		philo->l_fork = &prog->forks[(philo->id + 1) % prog->philo_count];
	}
	else
	{
		philo->l_fork = &prog->forks[philo->id];
		philo->r_fork = &prog->forks[(philo->id + 1) % prog->philo_count];
	}
}


static char	*init_single_philo(t_program *prog, char **av, int ac, int i)
{
	prog->philos[i].id = i;
	prog->philos[i].eaten_meals = 0;
	prog->philos[i].time_to_die = ft_atoi(av[2]);
	prog->philos[i].time_to_eat = ft_atoi(av[3]);
	prog->philos[i].time_to_sleep = ft_atoi(av[4]);
	prog->philos[i].last_meal = get_current_millis();
	if (prog->philos[i].last_meal == 0)
		return (GET_TIME_OF_DAY_ERROR);
	if (ac == 6)
		prog->philos[i].meals_to_finish = ft_atoi(av[5]);
	else
		prog->philos[i].meals_to_finish = -1;
	prog->philos[i].prog = prog;
	prog->philos[i].alive = true;
	prog->philos[i].must_eat = true;
	assign_forks(prog, &prog->philos[i]);
}

char	*init_philos(int ac, char **av, t_program *prog)
{
	int	i;

	prog->philos = malloc(prog->philo_count * sizeof(t_philo));
	if (!prog->philos)
		return (MEMORY_FAILURE);
	i = 0;
	while (i < prog->philo_count)
	{
		init_single_philo(prog, av, ac, i);
		i++;
	}
	return (NULL);
}


char	*init_program(t_program **prog_ptr, int ac, char **av)
{
	char	*error;

	*prog_ptr = malloc(sizeof(t_program));
	if (!*prog_ptr)
		return (MEMORY_FAILURE);
	pthread_mutex_init(&(*prog_ptr)->print_mutex, NULL);
	(*prog_ptr)->philo_count = ft_atoi(av[1]);
	pthread_mutex_init(&(*prog_ptr)->prog_mutex, NULL);
	(*prog_ptr)->forks = init_mutexes(*prog_ptr);
	if (!(*prog_ptr)->forks)
		return (MEMORY_FAILURE);
	error = init_philos(ac, av, *prog_ptr);
	if (error)
		return (error);
	return (NULL);
}
