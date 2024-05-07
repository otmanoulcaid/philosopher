/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:40:53 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/07 22:30:22 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	print(t_philo *philo, char *str)
{
	if (get_time() - get_last_meal(philo) < philo->data->time_to_die)
	{
		sem_wait(philo->data->sm_write);
		printf("%d %d %s\n", get_time() - philo->data->start, philo->id, str);
		sem_post(philo->data->sm_write);
	}
}

void	take_fork(t_philo *philo, sem_t *fork)
{
	if (get_time() - get_last_meal(philo) + philo->data->time_to_eat < \
	philo->data->time_to_die)
		(sem_wait(fork), print(philo, "has taken a fork"));
}

void	ft_sleep(t_philo *philo)
{
	if (get_time() - get_last_meal(philo) + philo->data->time_to_sleep < \
	philo->data->time_to_die)
	{
		print(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
	}
}

void	eat(t_philo *philo)
{
	if (get_time() - get_last_meal(philo) + philo->data->time_to_eat < \
	philo->data->time_to_die)
	{
		print(philo, "is eating");
		ft_usleep(philo->data->time_to_eat);
		philo->eaten_meals++;
		set_last_meal(philo);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
	}
}

void	think(t_philo *philo)
{
	if (get_time() - get_last_meal(philo) + philo->data->time_to_eat < \
	philo->data->time_to_die)
		print(philo, "is thinking");
}
