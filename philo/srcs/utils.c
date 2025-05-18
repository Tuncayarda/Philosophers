/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 05:50:56 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/18 08:05:36 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *msg)
{
	printf("%zu %zu %s\n", 
		get_current_millis() - philo->prog->start_time,
		philo->id + 1,
		msg);
}