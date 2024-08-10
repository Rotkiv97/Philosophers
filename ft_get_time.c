/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:15:57 by vguidoni          #+#    #+#             */
/*   Updated: 2023/04/17 17:16:03 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long int	get_time(t_philo *philo)
{
	unsigned long int	k;
	struct timeval		time;

	gettimeofday(&time, NULL);
	k = ((time.tv_sec - philo->t.tv_sec) * (unsigned long)1000)
		+ ((time.tv_usec - philo->t.tv_usec) / 1000);
	return (k);
}
