/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:53:30 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/05/06 21:22:43 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

/*------------------------structures-----------------------*/
typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				stop_simulation;
	int				start;
	pthread_mutex_t	write;
	pthread_mutex_t	d_time;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				eaten_meals;
	int				is_eating;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	m_data_start;
	pthread_mutex_t	m_stop_sim;
	pthread_mutex_t	m_eaten_meals;
	pthread_mutex_t	m_last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;
/*--------------------end of structures--------------------*/

/*------------------------functions------------------------*/
int		get_time(void);
void	*routine(void *arg);
void	destroy_data(t_data *data);
void	ft_usleep(size_t milisecond);
int		ft_atoi(char *str, int *nbr);
void	set_last_meal(t_philo *philo);
int		get_last_meal(t_philo *philo);
int		get_eaten_meal(t_philo *philo);
void	set_death_status(t_philo *philo, int value);
t_philo	*ft_init_data(t_data *data, char *av);
int		get_simulation_status(t_philo *philo);
int		simulate(t_philo *philo, int nb_philo);
void	ft_destroy(t_data data, t_philo *philo);
int		not_valid(t_data *data, int ac, char **av);

/*------------------------functions------------------------*/
#endif