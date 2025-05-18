/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:29:04 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/18 08:04:05 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dismantle_all(t_program *prog)
{
	size_t	i;

	i = 0;
	while(i < prog->philo_count)
	{
		pthread_detach(prog->philos[i].thread);
		i++;
	}
}

bool	check_all(t_program *prog)
{
	size_t	i;

	i = 0;
	while (i < prog->philo_count)
	{
		if (!prog->philos[i].alive)
		{
			dismantle_all(prog);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_death_status(t_program *prog, t_philo *philo, size_t idx)
{
	if ((get_current_millis() - prog->philos[idx].last_meal) > 
				prog->philos[idx].time_to_die)
	{
		philo_print(philo, "died");
		philo->alive = false;
		return (false);
	}
	return (true);
}

bool	check_meal_status(t_program *prog, t_philo *philo, size_t idx)
{
	size_t	i;
	
	i = 0;
	if (prog->philos[idx].eaten_meals == prog->philos[idx].meals_to_finish && 
			prog->philos[idx].alive)
	{
		prog->philos[idx].must_eat = false;
	}
	while (i < prog->philo_count && prog->philos[i].must_eat == false)
		i++;
	if (i == prog->philo_count)
	{
		dismantle_all(prog);
		return (false);
	}
		
	return (true);
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
				break;
			loop = check_meal_status(prog, &prog->philos[i], i);
			if (!loop)
				break;
			loop = check_all(prog);
			if (!loop)
				break;
			i++;
		}	
	}
}
