/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:56:07 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 20:16:37 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	not_valid(t_data *data, int ac, char **av)
{
	if (ac != 4 && ac != 5)
		return (printf("Error: not valid arguments\n"), 1);
	if (!ft_atoi(av[0], &data->nb_philo) || data->nb_philo <= 0 \
	|| data->nb_philo > 200)
		return (printf("Error: not valid number of philosophers\n"), 1);
	if (!ft_atoi(av[1], &data->time_to_die) || data->time_to_die < 60)
		return (printf("Error: not valid time to die\n"), 1);
	if (!ft_atoi(av[2], &data->time_to_eat) || data->time_to_eat < 60)
		return (printf("Error: not valid time to eat\n"), 1);
	if (!ft_atoi(av[3], &data->time_to_sleep) || data->time_to_sleep < 60)
		return (printf("Error: not valid time to sleep\n"), 1);
	if (av[4] && (!ft_atoi(av[4], &data->meals) || data->meals < 0))
		return (printf("Error: not valid number of meals\n"), 1);
	return (0);
}

int	ft_atoi(char *s, int *n)
{
	int	sign;

	sign = 1;
	*n = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s <= '9' && *s >= '0')
	{
		*n = (*n * 10) + *s - '0';
		s++;
	}
	if (*s || sign < 0)
		return (0);
	return (1);
}

t_philo	*ft_init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (printf("Error malloc\n"), NULL);
	i = -1;
	while (++i < data->nb_philo)
	{
		if (!i)
			philo[i].r_fork = data->forks + data->nb_philo - 1;
		else
			philo[i].r_fork = data->forks + i - 1;
		philo[i].l_fork = data->forks + i;
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].eaten_meals = 0;
		pthread_mutex_init(&philo[i].m_data_start, NULL);
		pthread_mutex_init(&philo[i].m_stop_sim, NULL);
		pthread_mutex_init(&philo[i].m_eaten_meals, NULL);
		pthread_mutex_init(&philo[i].m_last_meal, NULL);
	}
	return (philo);
}

t_philo	*ft_init_data(t_data *data, char *av)
{
	int		i;
	t_philo	*philo;

	if (av)
		ft_atoi(av, &data->meals);
	else
		data->meals = -1;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	data->nb_philo);
	if (!data->forks)
		return (printf("Error malloc\n"), NULL);
	data->stop_simulation = 0;
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->d_time, NULL);
	philo = ft_init_philo(data);
	if (!philo)
		return (destroy_data(data), NULL);
	return (philo);
}
