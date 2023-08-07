#include "thread.h"
#include "util/util.h"
#include <unistd.h>

#define DELAY 5000

void monitor_threads(t_wisdom *wisdoms)
{
	struct timeval now;
	unsigned int die_time;
	unsigned int i;

	die_time = wisdoms->data->config->die_time;
	while (true)
	{
		i = 0;
		gettimeofday(&now, NULL);
		while (i < wisdoms->data->config->num_philos)
		{
			pthread_mutex_lock(&wisdoms[i].last_eat_lock);
			if (difftimeval(wisdoms[i].last_eat, now) >= die_time)
			{
				pthread_mutex_lock(&wisdoms->data->terminate_lock);
				wisdoms->data->terminate = true;
				pthread_mutex_unlock(&wisdoms->data->terminate_lock);
				return ;
			}
			pthread_mutex_unlock(&wisdoms[i].last_eat_lock);
		}
		usleep(DELAY);
	}
}