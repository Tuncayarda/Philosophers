/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:29:43 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/16 14:51:48 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*init_mutexes(t_program *prog)
{
	size_t			i;
	pthread_mutex_t	*mtxs;

	i = 0;
	mtxs = malloc(sizeof(pthread_mutex_t) * prog->philo_count);
	while (i < prog->philo_count)
	{
		pthread_mutex_init(&mtxs[i], NULL);
		i++;
	}
	return (mtxs);
}

static void			assign_forks(t_program *prog, t_philo *philo)
{
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

static t_philo		*init_philos(int ac, char **av, t_program *prog)
{
	int	i;
	t_philo *philos;

	philos = malloc(prog->philo_count * sizeof(t_philo));
	if (!philos)
		handle_error(MEMORY_FAILURE, 1);
	i = 0; 
	while (i < prog->philo_count)
	{
		philos[i].id = i;
		philos[i].eaten_meals = 0;
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		philos[i].last_meal = get_current_millis();
		philos[i].meals_to_finish = -1;
		philos[i].prog = prog;
		assign_forks(prog, &philos[i]);
		if (ac == 6)
			philos[i].meals_to_finish = ft_atoi(av[5]) ;
		i++;
	}
	return (philos);
}


t_program	*init_program(int ac, char **av)
{
	size_t		i;
	t_program	*prog;

	prog = malloc(sizeof(t_program));
	if (!prog)
		handle_error(MEMORY_FAILURE, 1);
	prog->philo_count = ft_atoi(av[1]);
	pthread_mutex_init(&prog->prog_mutex, NULL);
	prog->forks = init_mutexes(prog);
	prog->philos = init_philos(ac, av, prog);
	return (prog);
}
