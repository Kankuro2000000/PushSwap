/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:35:55 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:36:25 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *hello)
{
	int	i;

	i = hello->a->value;
	hello->a->value = hello->a->next->value;
	hello->a->next->value = i;
	write(1, "sa", 2);
	write(1, "\n", 1);
}

void	swap_b(t_stacks *hello)
{
	int	i;

	i = hello->b->value;
	hello->b->value = hello->b->next->value;
	hello->b->next->value = i;
	write(1, "sb", 2);
	write(1, "\n", 1);
}

void	swap_ss(t_stacks *hello)
{
	swap_a(hello);
	swap_b(hello);
	write(1, "ss", 2);
	write(1, "\n", 1);
}

void	push_a(t_stacks *hello)
{
	t_stak	*buff;

	if (hello->b == NULL)
		return ;
	buff = hello->b;
	hello->b = hello->b->next;
	buff->next = hello->a;
	hello->a = buff;
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	push_b(t_stacks *hello)
{
	t_stak	*buff;

	if (hello->a == NULL)
		return ;
	buff = hello->a;
	hello->a = hello->a->next;
	buff->next = hello->b;
	hello->b = buff;
	write(1, "pb", 2);
	write(1, "\n", 1);
}
