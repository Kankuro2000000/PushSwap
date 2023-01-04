/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_right_and_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:38:15 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:39:03 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_right(t_stacks *hello)
{
	int		right_a;
	int		right_b;
	t_stak	*buff_a;
	t_stak	*buff_b;

	buff_a = hello->a;
	buff_b = hello->b;
	right_a = 1;
	right_b = 0;
	while (buff_a)
	{
		buff_a->right = right_a;
		right_a++;
		buff_a = buff_a->next;
	}
	while (buff_b)
	{
		buff_b->right = right_b;
		right_b++;
		buff_b = buff_b->next;
	}
}

void	find_back_a(t_stacks *hello)
{
	t_stak	*last_a;
	t_stak	*buff_a;
	int		back_a;

	last_a = stak_last(hello->a);
	back_a = last_a->right - 1;
	buff_a = hello->a;
	while (buff_a)
	{
		buff_a->back = back_a;
		back_a--;
		buff_a = buff_a->next;
	}
}

void	find_back_b(t_stacks *hello)
{
	t_stak	*last_b;
	t_stak	*buff_b;
	int		back_b;

	last_b = stak_last(hello->b);
	back_b = last_b->right + 1;
	buff_b = hello->b;
	while (buff_b)
	{
		buff_b->back = back_b;
		back_b--;
		buff_b = buff_b->next;
	}
}
