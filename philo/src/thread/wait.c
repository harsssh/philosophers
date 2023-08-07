#include <pthread.h>

void wait_threads(pthread_t *philos, unsigned int num_philos)
{
	unsigned int i;

	i = 0;
	while (i < num_philos)
		pthread_join(philos[i++], NULL);
}