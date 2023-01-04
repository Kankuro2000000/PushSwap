/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:42:27 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:42:59 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stacks *hello)
{
	t_stak	*buff_a;
	t_stak	*last;
	int		count;

	count = stak_last(hello->a)->right;
	buff_a = hello->a;
	if (count == 5)
	{
		act_for_5(hello, count);
		return ;
	}
	while (count != 3)
	{
		last = stak_last(hello->a);
		if ((hello->a->value != hello->min) && (hello->a->value != hello->mid)
			&& (hello->a->value != hello->max))
			push_b(hello);
		else if ((last->value != hello->min)
			&& (last->value != hello->mid) && (last->value != hello->max))
			rev_rotate_a(hello);
		else
			rotate_a(hello);
		find_right(hello);
		count = stak_last(hello->a)->right;
	}
}

int	find_min(t_stak *buff)
{
	if (buff->right > buff->back)
		return (buff->back);
	return (buff->right);
}

int	cost_place(t_stak *buff_a, t_stak *buff_b, t_stak *last_a)
{
	if (buff_b->value > last_a->value && buff_b->value < buff_a->value)
	{
		buff_b->place = find_min(last_a) + find_min(buff_b);
		return (1);
	}
	else if (buff_b->value > buff_a->value
		&& buff_b->value < buff_a->next->value)
	{
		buff_b->place = find_min(buff_a) + find_min(buff_b);
		return (1);
	}
	return (0);
}

void	find_cost_place(t_stacks *hello)
{
	t_stak	*buff_a;
	t_stak	*buff_b;
	t_stak	*last_a;

	buff_b = hello->b;
	last_a = stak_last(hello->a);
	while (buff_b)
	{
		buff_a = hello->a;
		while (buff_a->next)
		{
			if (cost_place(buff_a, buff_b, last_a))
				break ;
			buff_a = buff_a->next;
		}
		buff_b = buff_b->next;
	}
}
