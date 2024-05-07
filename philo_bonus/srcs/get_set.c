/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:34:11 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 23:49:22 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	get_last_meal(t_philo *philo)
{
	int	last_m;

	sem_wait(philo->sem_last_meal);
	last_m = philo->last_meal;
	sem_post(philo->sem_last_meal);
	return (last_m);
}

void	set_last_meal(t_philo *philo)
{
	sem_wait(philo->sem_last_meal);
	philo->last_meal = get_time();
	sem_post(philo->sem_last_meal);
}
