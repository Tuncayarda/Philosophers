#include "philo.h"

size_t get_current_millis(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		terminate_prog("GET TIME OF DAY ERROR" , 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
