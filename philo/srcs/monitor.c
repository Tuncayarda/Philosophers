/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:29:04 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/19 22:11:28 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death_status(t_program *prog, t_philo *philo, size_t idx)
{
	size_t	i;

	pthread_mutex_lock(&prog->state_mutex);
	if (get_current_millis()
		- prog->philos[idx].last_meal > prog->philos[idx].time_to_die)
	{
		i = 0;
		while (i < prog->philo_count)
			prog->philos[i++].alive = false;
		pthread_mutex_unlock(&prog->state_mutex);
		philo_print(philo, "died");
		pthread_mutex_lock(&prog->state_mutex);
		prog->finished = true;
		pthread_mutex_unlock(&prog->state_mutex);
		return (false);
	}
	pthread_mutex_unlock(&prog->state_mutex);
	return (true);
}

static void	clear_all(t_program *prog)
{
	size_t	i;

	i = 0;
	while (i < prog->philo_count)
		prog->philos[i++].alive = false;
}

bool	check_meal_status(t_program *prog, t_philo *philo, size_t idx)
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
		clear_all(prog);
	pthread_mutex_unlock(&prog->state_mutex);
	return (i != prog->philo_count);
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
			loop = check_death_status(prog, &prog->philos[i], i);
			if (!loop)
				break ;
			loop = check_meal_status(prog, &prog->philos[i], i);
			if (!loop)
				break ;
			i++;
		}
	}
}
