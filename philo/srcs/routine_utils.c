/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:02:30 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/24 14:40:14 by tuaydin          ###   ########.fr       */
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
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		philo_print(philo, "has taken a fork");
	}
}

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	philo_print(philo, "is eating");
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(&philo->prog->state_mutex);
	if (philo->meals_to_finish != -1)
		philo->eaten_meals++;
	philo->last_meal = get_current_millis();
	pthread_mutex_unlock(&philo->prog->state_mutex);
	leave_forks(philo);
}
