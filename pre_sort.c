/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:41:16 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:41:55 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = len - 1;
	while (i > 0)
	{
		j = 0;
		while (i > j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
}

void	min_mid_max(int *array, int len, t_stacks *hello)
{
	hello->min = array[0];
	hello->max = array[len - 1];
	hello->mid = array[(len - 1) / 2];
}

int	check_t_stacksort(t_stak *buff, t_stacks *hello)
{
	t_stak	*last;

	last = stak_last(hello->a);
	if (buff->value < buff->next->value && last->value > buff->next->value)
		return (1);
	return (0);
}
