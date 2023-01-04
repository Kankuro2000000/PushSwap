/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:34:25 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:34:42 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid(int argc, char **argv)
{
	if (check_duplic(argc, argv) && argc > 2)
		return (1);
	if (check_alfa(argc, argv))
		return (1);
	if (check_int(argc, argv))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	map_to_int(int *map_int, char **map)
{
	int	i;

	i = 1;
	while (map[i] != NULL)
	{
		map_int[i - 1] = (int)ft_atoi(map[i]);
		i++;
	}
}

int	*malloc_array(char **map)
{
	int	i;
	int	*int_map;

	i = 1;
	while (map[i] != NULL)
		i++;
	int_map = (int *)malloc(sizeof(int) * (i - 1));
	if (int_map == NULL)
		return (NULL);
	map_to_int(int_map, map);
	return (int_map);
}

int	check_sort(int *array, int len)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			flag++;
		if (flag >= 2)
			return (0);
		i++;
	}
	if (flag == 1 && array[0] < array[i])
		return (0);
	return (1);
}
