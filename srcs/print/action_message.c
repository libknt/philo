/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:30:11 by keys              #+#    #+#             */
/*   Updated: 2023/01/07 20:09:50 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	action_message(char *mes, t_philo *philo)
{
	size_t	time;
	bool	ans;

	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->is_death);
	ans = philo->is_dead;
	pthread_mutex_unlock(&philo->is_death);
	if (!ans)
	{
		time = get_time() - philo->data->start;
		printf(mes, time, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->print);
	return (1);
}
