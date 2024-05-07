/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:55:33 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 20:00:36 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (not_valid(&data, ac - 1, av + 1))
		return (1);
	philo = ft_init_data(&data, av[5]);
	if (!philo)
		return (2);
	if (!simulate(philo, data.nb_philo))
		return (ft_destroy(data, philo), printf("Error: pthread error\n"), 3);
	ft_destroy(data, philo);
	return (0);
}
