/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:47:30 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/07 18:30:40 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	sem_wait(philo->data->sem_finish);
	i = -1;
	while (++i < philo->data->nb_philo)
		kill(philo[i].pid, 9);
	return (NULL);
}

void	*supervisor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_time() - get_last_meal(philo) > philo->data->time_to_die)
		{
			sem_wait(philo->data->sem_write);
			printf("%d %d died\n", get_time() - philo->data->start, philo->id);
			sem_post(philo->data->sem_finish);
			return (NULL);
		}
	}
	return (NULL);
}
