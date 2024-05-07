/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:20:33 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/07 22:30:22 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	clean(t_philo *philo)
{
	sem_close(philo->data->sem_finish);
	sem_close(philo->data->sm_write);
	sem_close(philo->data->forks);
	sem_unlink("sem_finish");
	sem_unlink("sem_forks");
	sem_unlink("sm_write");
}
