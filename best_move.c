/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:43:13 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:45:16 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stak	*find_best_move(t_stak *buff)
{
	t_stak	*best_move;

	best_move = buff;
	while (buff)
	{
		if (best_move->place > buff->place)
			best_move = buff;
		buff = buff->next;
	}
	return (best_move);
}

t_stak	*find_good_place(t_stak *buff, t_stak *best_move)
{
	t_stak	*last;

	last = stak_last(buff);
	while (buff->next)
	{
		if (best_move->value > last->value && best_move->value < buff->value)
			return (last);
		if (best_move->value > buff->value
			&& best_move->value < buff->next->value)
			return (buff);
		buff = buff->next;
	}
	return (buff);
}

void	move_a(t_stacks *hello, t_stak *good_place)
{
	if (good_place->right <= good_place->back)
	{
		while (good_place->right > 0)
		{
			rotate_a(hello);
			good_place->right--;
		}
	}
	else
	{
		while (good_place->back > 0)
		{
			rev_rotate_a(hello);
			good_place->back--;
		}
	}
}

void	move_b(t_stacks *hello, t_stak *best_move)
{
	if (best_move->right <= best_move->back)
	{
		while (best_move->right > 0)
		{
			rotate_b(hello);
			best_move->right--;
		}
	}
	else
	{
		while (best_move->back > 0)
		{
			rev_rotate_b(hello);
			best_move->back--;
		}
	}
}

void	main_sort(t_stacks *hello)
{
	t_stak	*best_move;
	t_stak	*good_place;

	best_move = find_best_move(hello->b);
	if (best_move->place == 0)
	{
		push_a(hello);
		return ;
	}
	good_place = find_good_place(hello->a, best_move);
	move_a(hello, good_place);
	move_b(hello, best_move);
	push_a(hello);
}
