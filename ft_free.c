/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:20:49 by vguidoni          #+#    #+#             */
/*   Updated: 2023/04/17 17:20:52 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_philo *philo)
{
	free(philo->fork);
	free(philo->ult_mang);
	free(philo->tphilo);
	free(philo);
}
