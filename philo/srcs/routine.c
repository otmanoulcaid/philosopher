/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:56:58 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 21:21:37 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->write);
	if (!get_simulation_status(philo))
		printf("%d %d %s\n", get_time() - philo->data->start, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

static void	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print(philo, "has taken a fork");
}

static void	ft_eat(t_philo *philo)
{
	print(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	set_last_meal(philo);
	pthread_mutex_lock(&philo->m_eaten_meals);
	philo->eaten_meals++;
	pthread_mutex_unlock(&philo->m_eaten_meals);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	ft_sleep(t_philo *philo)
{
	print(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1)
	{
		take_fork(philo, philo->r_fork);
		ft_usleep(philo->data->time_to_die);
		return (NULL);
	}
	set_last_meal(philo);
	if (philo->id % 2)
		ft_usleep(philo->data->time_to_eat);
	while (1)
	{
		if (get_simulation_status(philo))
			break ;
		take_fork(philo, philo->r_fork);
		take_fork(philo, philo->l_fork);
		ft_eat(philo);
		ft_sleep(philo);
		print(philo, "is thinking");
	}
	return (NULL);
}
