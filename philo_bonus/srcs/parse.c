/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:49:35 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/07 22:31:26 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	free_open(t_philo *philo, int i)
{
	int		j;
	char	*str;

	j = -1;
	while (++j < i)
	{
		str = itoa(i);
		if (!str)
			return (printf(ERR_MAL), exit(EXIT_FAILURE));
		(sem_close(philo[i].sem_last_meal), sem_unlink(str));
		free(str);
	}
}

int	not_valid(t_data *data, int ac, char **av)
{
	if (ac != 4 && ac != 5)
		return (printf("Error: bad arguments\n"));
	if (!ft_atoi(av[0], &data->nb_philo) || data->nb_philo < 1 \
	|| data->nb_philo > 200)
		return (printf("Error: bad number of philosophers\n"));
	if (!ft_atoi(av[1], &data->time_to_die) || data->time_to_die < 60 \
	|| data->time_to_die > 10000)
		return (printf("Error: bad time to die\n"));
	if (!ft_atoi(av[2], &data->time_to_eat) || data->time_to_eat < 60 \
	|| data->time_to_eat > 10000)
		return (printf("Error: bad time to eat\n"));
	if (!ft_atoi(av[3], &data->time_to_sleep) || data->time_to_sleep < 60 \
	|| data->time_to_sleep > 10000)
		return (printf("Error: bad time to sleep\n"));
	if (av[4] && (!ft_atoi(av[4], &data->meals) || data->meals < 0 \
	|| data->meals > 200))
		return (printf("Error: bad number of meals\n"));
	return (0);
}

int	ft_atoi(char *s, int *n)
{
	long	nbr;
	int		sign;

	sign = 1;
	nbr = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s <= '9' && *s >= '0')
	{
		nbr = (nbr * 10) + *s - '0';
		s++;
		if (nbr >= INT_MAX)
			return (0);
	}
	if (*s || sign < 0)
		return (0);
	*n = (int)nbr;
	return (1);
}

t_philo	*ft_init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;
	char	*str;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (printf(ERR_MAL), NULL);
	i = -1;
	while (++i < data->nb_philo)
	{
		str = itoa(i);
		if (!str)
			(free_open(philo, i - 1), free(philo), exit(EXIT_FAILURE));
		sem_unlink(str);
		philo[i].sem_last_meal = sem_open(str, O_CREAT, 0644, 1);
		if (!philo[i].sem_last_meal)
			(free_open(philo, i - 1), free(philo), free(str), \
			exit(EXIT_FAILURE));
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].eaten_meals = 0;
		free(str);
	}
	return (philo);
}

t_philo	*ft_init_data(t_data *data, int ac, char **av)
{
	t_philo	*philo;

	if (ac == 5)
		ft_atoi(av[4], &data->meals);
	else
		data->meals = -1;
	sem_unlink("sem_forks");
	sem_unlink("sm_write");
	sem_unlink("sem_finish");
	data->forks = sem_open("sem_forks", O_CREAT, 664, data->nb_philo);
	if (!data->forks)
		(printf(ERR_OPEN), exit(EXIT_FAILURE));
	data->sm_write = sem_open("sm_write", O_CREAT, 664, 1);
	if (!data->sm_write)
		(printf(ERR_OPEN), sem_close(data->forks), \
		sem_unlink("sem_forks"), exit(EXIT_FAILURE));
	data->sem_finish = sem_open("sem_finish", O_CREAT, 664, 0);
	if (!data->sem_finish)
		(sem_unlink("sem_finish"), sem_unlink("sem_forks"), printf(ERR_OPEN), \
		sem_close(data->sm_write), sem_close(data->forks), exit(EXIT_FAILURE));
	philo = ft_init_philo(data);
	if (!philo)
		return (clean(philo), NULL);
	return (philo);
}
