/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:54:19 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/04 16:48:45 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(data->forks + i);
	pthread_mutex_destroy(&data->write);
	free(data->forks);
}

void	ft_destroy(t_data data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data.nb_philo)
	{
		pthread_mutex_destroy(&philo[i].m_last_meal);
		pthread_mutex_destroy(&philo[i].m_eaten_meals);
		pthread_mutex_destroy(&philo[i].m_stop_sim);
	}
	free(philo);
	destroy_data(&data);
}
