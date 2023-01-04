/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:39:37 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:40:42 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stacks *hello)
{
	if (hello->a->value > hello->a->next->value
		&& hello->a->value > hello->a->next->next->value)
		rotate_a(hello);
	if (hello->a->value < hello->a->next->value
		&& hello->a->next->value > hello->a->next->next->value)
		rev_rotate_a(hello);
	if (hello->a->value > hello->a->next->value)
		swap_a(hello);
}

void	act_for_5(t_stacks *hello, int count)
{
	while (count != 3)
	{
		if (hello->a->value == hello->min || hello->a->value == hello->max)
			push_b(hello);
		else
			rotate_a(hello);
		find_right(hello);
		count = stak_last(hello->a)->right;
	}
	sort_3(hello);
	push_a(hello);
	push_a(hello);
	if (hello->a->value == hello->max)
		rotate_a(hello);
	else
	{
		swap_a(hello);
		rotate_a(hello);
	}
}
