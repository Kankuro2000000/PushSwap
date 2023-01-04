/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:32:33 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:33:08 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

int	check_duplic(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc - 1)
	{
		k = 1;
		while (k < argc - i)
		{
			if (ft_strcmp(argv[i], argv[k + i]) == 0)
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int64_t	ft_atoi(char *str)
{
	int		i;
	int64_t	sign;
	int64_t	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + res * 10;
		i++;
	}
	return (res * sign);
}

int	check_int(int argc, char **argv)
{
	int		i;
	int64_t	res;

	i = 1;
	while (i < argc)
	{
		res = ft_atoi(argv[i]);
		if (res >= 2147483648 || res <= -2147483649)
			return (1);
		i++;
	}
	return (0);
}

int	check_alfa(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		if (argv[i][0] == '-' && (argv[i][1] >= '0' && argv[i][1] <= '9'))
			k++;
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}
