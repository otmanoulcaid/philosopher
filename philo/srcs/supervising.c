/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervising.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:36:23 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 21:21:58 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*supervising(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = -1;
		while (++i < philo->data->nb_philo)
		{
			if (get_eaten_meal(philo) == philo->data->meals)
				return (set_death_status(philo, 1), NULL);
			if (get_time() - get_last_meal(philo + i) > \
			philo->data->time_to_die)
			{
				set_death_status(philo, 1);
				return (printf("%u %d died\n", get_time() - philo->data->start, \
				philo->id), NULL);
			}
		}
	}
	return (NULL);
}

static void	join(t_philo *philo, int nb_philo)
{
	int	i;

	i = -1;
	while (++i < nb_philo)
		pthread_join(philo[i].thread, NULL);
}

int	simulate(t_philo *philo, int nb_philo)
{
	int			i;
	pthread_t	thread;

	if (!philo->data->meals)
		return (1);
	i = -1;
	philo->data->start = get_time();
	while (++i < nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, philo + i))
			return (0);
	}
	if (pthread_create(&thread, NULL, &supervising, philo))
		return (0);
	pthread_join(thread, NULL);
	join(philo, nb_philo);
	return (1);
}
