/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:18:42 by tuaydin           #+#    #+#             */
/*   Updated: 2025/05/20 04:33:26 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_error(char *msg, t_program *program)
{
	if (msg)
		printf("ERROR: %s\n", msg);
	if (program)
		set_program_free(program);
	return (1);
}

int	main(int ac, char **av)
{
	t_program	*program;
	char		*error_msg;

	program = NULL;
	error_msg = check_errors(ac, av);
	if (error_msg)
		return (handle_error(error_msg, NULL));
	error_msg = init_program(&program, ac, av);
	if (error_msg)
		return (handle_error(error_msg, program));
	error_msg = born_philos(program);
	if (error_msg)
		return (handle_error(error_msg, program));
	set_program_free(program);
	return (0);
}
