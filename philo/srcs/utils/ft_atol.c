/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:51:55 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/07 14:52:09 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	ft_overlong(const char *str, unsigned long long result,
		int base, long long flag)
{
	unsigned long long	cutoff;
	unsigned long long	last;

	cutoff = (unsigned long long)LONG_MAX / (unsigned long long)base;
	last = (unsigned long long)LONG_MAX % (unsigned long long)base;
	if (result > cutoff)
		return (flag);
	else if (result <= cutoff)
	{
		if (((result == cutoff) && (((unsigned long long)(*str - '0')) <= last))
			|| (result < cutoff))
		{
			result *= (unsigned long long)base;
			result += (unsigned long long)(*str - '0');
			str++;
			if (((result < cutoff)) && ft_isdigit(str[1]) == 0)
				return (flag);
		}
		else
			return (flag);
	}
	if (flag == (long long)LONG_MIN)
		return ((long long)result * -1LL);
	return ((long long)result);
}

static long long	ft_strtol(const char *str, int base, long long flag)
{
	unsigned long long	result;

	result = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (result >= ((unsigned long long)LONG_MAX
					/ (unsigned long long)base))
				return (ft_overlong(str, result, base, flag));
			result *= (unsigned long long)base;
			result += (unsigned long long)(*str - '0');
			str++;
		}
		else
			break ;
	}
	if (flag == (long long)LONG_MIN)
	{
		return ((long long)result * -1LL);
	}
	return ((long long)result);
}

long	ft_atol(const char *nptr)
{
	long long	ans;
	long long	flag;
	int			i;

	i = 0;
	flag = LONG_MAX;
	while (ft_isspace((int)nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		flag = LONG_MIN;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	ans = ft_strtol(&nptr[i], 10, flag);
	return ((long)ans);
}
