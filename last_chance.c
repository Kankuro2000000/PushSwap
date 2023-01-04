/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_chance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:45:26 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:46:00 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack_sort(t_stacks *hello)
{
	t_stak	*buff;
	t_stak	*last;

	buff = hello->a;
	last = stak_last(hello->a);
	if (buff->value > last->value && last->value > buff->next->value)
		return ;
	if (buff->value < buff->next->value && buff->next->value < last->value)
		return ;
	if (buff->value < buff->next->value && buff->value > last->value)
		return ;
	swap_a(hello);
}

void	last_chance_rotate(t_stak *buff, t_stacks *hello)
{
	while (buff->right > 1)
	{
		rotate_a(hello);
		buff->right--;
	}
}

void	last_chance_rev_rotate(t_stak *buff, t_stacks *hello)
{
	while (buff->back >= 0)
	{
		rev_rotate_a(hello);
		buff->back--;
	}
}

void	last_chance(t_stacks *hello, int min)
{
	t_stak	*buff;

	buff = hello->a;
	find_right(hello);
	find_back_a(hello);
	while (buff->value != min)
		buff = buff->next;
	if (buff->right > buff->back + 1)
		last_chance_rev_rotate(buff, hello);
	else
		last_chance_rotate(buff, hello);
}
