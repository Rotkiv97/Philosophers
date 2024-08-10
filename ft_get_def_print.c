/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_def_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:36:15 by vguidoni          #+#    #+#             */
/*   Updated: 2023/04/17 17:36:22 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	ft_print(t_arrphilo *tphilo, char *msg, int k)
{
	pthread_mutex_lock(tphilo->die);
	pthread_mutex_lock(tphilo->mutex);
	if (tphilo->filo->count_die)
		tphilo->filo->count_die = 1;
	else if (!tphilo->filo->count_die)
		printf("%ldms   %d   %s  \n", get_time(tphilo->filo), k, msg);
	pthread_mutex_unlock(tphilo->mutex);
	pthread_mutex_unlock(tphilo->die);
}

void	ft_print_def(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->mutex);
	printf("%ldms  %d   %s\n", get_time(philo), i + 1, "died");
	pthread_mutex_unlock(&philo->mutex);
	philo->count_die = 1;
	pthread_mutex_unlock(&philo->die);
}

void	ft_init_def(t_philo *philo)
{
	pthread_mutex_lock(&philo->die);
	philo->count_die = 0;
	pthread_mutex_unlock(&philo->die);
	philo->tphilo->count_it = 0;
}

void	ft_gest_morte(t_philo *philo, int i)
{
	while (i <= philo->filosofi)
	{
		pthread_mutex_lock(&philo->die);
		if (i == philo->filosofi)
			i = 0;
		if (philo->tphilo->count_it == philo->turni)
		{
			pthread_mutex_unlock(&philo->die);
			break ;
		}
		if (i < philo->filosofi && (get_time(philo))
			- (long unsigned int)philo->ult_mang[i]
			> (long unsigned int)philo->morte
			&& philo->tphilo->count_it < philo->turni)
		{
			ft_print_def(philo, i);
			break ;
		}
		pthread_mutex_unlock(&philo->die);
		if (philo->count_die)
			break ;
		i++;
	}
}

void	ft_death(t_philo *philo)
{
	int	i;

	i = 0;
	ft_init_def(philo);
	ft_gest_morte(philo, i);
}
