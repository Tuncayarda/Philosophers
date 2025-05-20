/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:29:04 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/20 21:39:28 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death_status(t_program *prog, size_t idx)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&prog->state_mutex);
	if (get_current_millis()
		- prog->philos[idx].last_meal > prog->philos[idx].time_to_die)
	{
		pthread_mutex_unlock(&prog->state_mutex);
		philo_print(&prog->philos[idx], "died");
		pthread_mutex_lock(&prog->state_mutex);
		prog->finished = true;
		while (i < prog->philo_count)
			prog->philos[i++].alive = false;
		pthread_mutex_unlock(&prog->state_mutex);
		return (false);
	}
	pthread_mutex_unlock(&prog->state_mutex);
	return (true);
}

bool	check_meal_status(t_program *prog, size_t idx)
{
	size_t	i;

	pthread_mutex_lock(&prog->state_mutex);
	if (prog->philos[idx].meals_to_finish != -1
		&& prog->philos[idx].eaten_meals == prog->philos[idx].meals_to_finish
		&& prog->philos[idx].alive)
		prog->philos[idx].must_eat = false;
	i = 0;
	while (i < prog->philo_count && !prog->philos[i].must_eat)
		i++;
	if (i == prog->philo_count)
	{
		i = 0;
		while (i < prog->philo_count)
			prog->philos[i++].alive = false;
		prog->finished = true;
	}
	pthread_mutex_unlock(&prog->state_mutex);
	return (i != prog->philo_count);
}

void	routine_check(t_program *prog)
{
	size_t	i;

	while (!prog->finished)
	{
		i = 0;
		while (i < prog->philo_count && !prog->finished)
		{
			if (!check_death_status(prog, i))
				break ;
			if (prog->philos[0].meals_to_finish != -1)
				if (!check_meal_status(prog, i))
					break ;
			i++;
		}
	}
}
