/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:37:13 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:37:43 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stacks *hello)
{
	t_stak	*last;
	t_stak	*buff;
	t_stak	*pre_last;

	buff = hello->a;
	while (buff->next->next)
		buff = buff->next;
	pre_last = buff;
	buff = hello->a;
	last = stak_last(hello->a);
	hello->a = last;
	last->next = buff;
	pre_last->next = NULL;
	write(1, "rra", 3);
	write(1, "\n", 1);
}

void	rev_rotate_b(t_stacks *hello)
{
	t_stak	*last;
	t_stak	*buff;
	t_stak	*pre_last;

	buff = hello->b;
	if (buff->next == NULL)
	{
		rotate_b(hello);
		return ;
	}
	while (buff->next->next)
		buff = buff->next;
	pre_last = buff;
	buff = hello->b;
	last = stak_last(hello->b);
	hello->b = last;
	last->next = buff;
	pre_last->next = NULL;
	write(1, "rrb", 3);
	write(1, "\n", 1);
}

void	rev_rotate(t_stacks *hello)
{
	rev_rotate_a(hello);
	rev_rotate_b(hello);
	write(1, "rrr", 3);
	write(1, "\n", 1);
}
