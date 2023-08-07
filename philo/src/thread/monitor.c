#include "thread.h"
#include "util/util.h"
#include "internal.h"
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
		while (i < wisdoms->data->config->num_philos)
		{
			gettimeofday(&now, NULL);
			pthread_mutex_lock(&wisdoms[i].last_eat_lock);
			if (difftimeval(wisdoms[i].last_eat, now) >= die_time)
			{
				print_log(wisdoms + i, MSG_DIE);
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