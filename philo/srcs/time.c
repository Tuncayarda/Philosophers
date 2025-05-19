/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:48:48 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/19 20:48:49 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_millis(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = get_current_millis();
	while (get_current_millis() - start < mls)
		usleep(500);
}
