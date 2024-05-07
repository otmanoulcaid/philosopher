/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:38 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 23:50:04 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	main(int ac, char **av)
{
	int		i;
	t_data	data;
	t_philo	*philo;

	if (not_valid(&data, ac - 1, av + 1))
		return (1);
	philo = ft_init_data(&data, ac - 1, av + 1);
	if (!philo)
		return (2);
	if (!simulate(philo, data.nb_philo))
		return (clean(philo), 3);
	i = -1;
	while (++i < data.nb_philo)
		waitpid(philo[i].pid, NULL, 0);
	return (clean(philo), 0);
}

	// atexit(check);
// void	check(void)
// {
// 	system("lsof -c philo_bonus");
// }