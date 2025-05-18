/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:37 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/18 05:30:11 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	check_meal_status(t_program *prog, t_philo *philo, size_t idx)
{
	if (prog->philos[idx].eaten_meals == prog->philos[idx].meals_to_finish && 
			prog->philos[idx].must_eat)
	{
		prog->philos[idx].must_eat = false;
		prog->finished_philos++;
	}
}

void	routine_check(t_program *prog)
{
	size_t	i;
	bool	loop;

	loop = true;
	while (loop)
	{
		i = 0;
		while (i < prog->philo_count)
		{
			if ((get_current_millis() - prog->philos[i].last_meal) > 
				prog->philos[i].time_to_die)
			{
				loop = false;
				philo_print(&prog->philos[i], "died");
				break;
			}
			check_meal_status(prog, &prog->philos[i], i);
			if (prog->finished_philos == prog->philo_count)
			{
				loop = false;
				break;
			}
			i++;
		}	
	}
}

void	born_check(t_program *prog)
{
	pthread_mutex_lock(&prog->prog_mutex);
	while (1)
	{ 
		if (prog->philo_count == prog->thread_count)
			break;
	}
	pthread_mutex_unlock(&prog->prog_mutex);
}

void	*live(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	born_check(philo->prog);
	philo->prog->start_time = get_current_millis();
	if (philo->id % 2 != 0)
		ft_usleep(10);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

void	born_philos(t_program *prog)
{
	size_t	i;

	i = 0;
	prog->thread_count = 0;

	while (prog->thread_count < prog->philo_count)
	{
		pthread_create(&prog->philos[prog->thread_count].thread, 
				NULL, live, &prog->philos[prog->thread_count]);
		prog->thread_count++;
	}
	routine_check(prog);
}
