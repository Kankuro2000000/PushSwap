/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:36:27 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:37:09 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *hello)
{
	t_stak	*last;
	t_stak	*buff;

	buff = hello->a;
	last = stak_last(hello->a);
	last->next = hello->a;
	hello->a = hello->a->next;
	buff->next = NULL;
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	rotate_b(t_stacks *hello)
{
	t_stak	*last;
	t_stak	*buff;

	buff = hello->b;
	last = stak_last(hello->b);
	last->next = hello->b;
	hello->b = hello->b->next;
	buff->next = NULL;
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	rotate(t_stacks *hello)
{
	rotate_a(hello);
	rotate_b(hello);
	write(1, "rr", 2);
	write(1, "\n", 1);
}
