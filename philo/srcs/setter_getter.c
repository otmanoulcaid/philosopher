/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:40:33 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 21:22:33 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_simulation_status(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->m_stop_sim);
	status = philo->data->stop_simulation;
	pthread_mutex_unlock(&philo->m_stop_sim);
	return (status);
}

void	set_death_status(t_philo *philo, int value)
{
	pthread_mutex_lock(&philo->m_stop_sim);
	philo->data->stop_simulation = value;
	pthread_mutex_unlock(&philo->m_stop_sim);
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_last_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->m_last_meal);
}

int	get_last_meal(t_philo *philo)
{
	int	last_meal;

	pthread_mutex_lock(&philo->m_last_meal);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->m_last_meal);
	return (last_meal);
}

int	get_eaten_meal(t_philo *philo)
{
	int	get_nbr_meal;

	pthread_mutex_lock(&philo->m_eaten_meals);
	get_nbr_meal = philo->eaten_meals;
	pthread_mutex_unlock(&philo->m_eaten_meals);
	return (get_nbr_meal);
}
