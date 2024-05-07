/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:24:38 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/07 19:00:57 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	routine(t_philo	*philo, t_data *data)
{
	pthread_t	thread;

	philo->last_meal = get_time();
	if (data->nb_philo == 1)
	{
		take_fork(philo, data->forks);
		(ft_usleep(data->time_to_die), print(philo, "died"));
		exit(EXIT_SUCCESS);
	}
	pthread_create(&thread, NULL, &supervisor, philo);
	while (1)
	{
		if (philo->eaten_meals == philo->data->meals)
			(ft_usleep(1), sem_post(philo->data->sem_finish));
		if (get_time() - get_last_meal(philo) < philo->data->time_to_die)
		{
			(take_fork(philo, data->forks), take_fork(philo, data->forks));
			(eat(philo), ft_sleep(philo), think(philo));
		}
	}
	exit(EXIT_SUCCESS);
}

int	simulate(t_philo *philo, int nb_philo)
{
	int			i;
	pthread_t	thread;

	i = -1;
	philo->data->start = get_time();
	if (!philo->data->meals)
		return (1);
	while (++i < nb_philo)
	{
		philo[i].pid = fork();
		if (!philo[i].pid)
			routine(philo + i, philo->data);
	}
	if (pthread_create(&thread, NULL, &monitor, philo))
	{
		(sem_unlink("sem_forks"), sem_unlink("sem_write"));
		return (printf("Error pthread\n"), 0);
	}
	return (1);
}
