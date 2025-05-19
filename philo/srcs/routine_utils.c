/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:02:30 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/19 20:27:46 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
	philo_print(philo, "is thinking");
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	take_forks(t_philo *philo)
{
	size_t			count;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	count = philo->prog->philo_count;
	if (philo->id < (philo->id + 1) % count)
	{
		first = &philo->prog->forks[philo->id];
		second = &philo->prog->forks[(philo->id + 1) % count];
	}
	else
	{
		first = &philo->prog->forks[(philo->id + 1) % count];
		second = &philo->prog->forks[philo->id];
	}
	pthread_mutex_lock(first);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(second);
	philo_print(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	philo_print(philo, "is eating");
	pthread_mutex_lock(&philo->prog->state_mutex);
	philo->last_meal = get_current_millis();
	if (philo->meals_to_finish != -1)
		philo->eaten_meals++;
	pthread_mutex_unlock(&philo->prog->state_mutex);
	ft_usleep(philo->time_to_eat);
	leave_forks(philo);
}
