#include "thread.h"
#include "util/util.h"
#include <pthread.h>
#include <stdlib.h>

static pthread_mutex_t	*create_forks(t_philo_config config)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * config.num_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < config.num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			while (i--)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

static unsigned int calc_eat_interval(t_philo_config config)
{
	const unsigned int n = config.num_philos;
	const unsigned int k = n / 2;
	unsigned int candidate;

	candidate = (unsigned int)ft_ceil((double)n * config.eat_time / k);
	return ft_max(candidate, config.eat_time + config.sleep_time);
}

static void init_shared_data(t_shared_data *data, t_philo_config config)
{
	data->config = config;
	data->terminate = false;
	gettimeofday(&data->start_time, NULL);
	data->start_time = timeval_add_ms(data->start_time, MSEC_IN_SEC);
	data->eat_interval = calc_eat_interval(config);
}

t_shared_data	*create_shared_data(t_philo_config config)
{
	t_shared_data	*data;

	data = malloc(sizeof(t_shared_data));
	if (data == NULL)
		return (NULL);
	data->forks = create_forks(config);
	if (data->forks == NULL)
	{
		free(data);
		return (NULL);
	}
	if (pthread_mutex_init(&data->lock, NULL))
	{
		free(data->forks);
		free(data);
		return (NULL);
	}
	init_shared_data(data, config);
	return (data);
}
