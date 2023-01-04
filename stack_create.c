/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:35:05 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:35:40 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*stack_create(int value)
{
	t_stacks	*final_stack;

	final_stack = malloc(sizeof(t_stacks));
	if (!final_stack)
		return (NULL);
	final_stack->a = malloc(sizeof(t_stak));
	if (!final_stack->a)
	{
		free_stacks(final_stack);
		return (NULL);
	}
	final_stack->a->value = value;
	final_stack->a->next = NULL;
	final_stack->b = NULL;
	return (final_stack);
}

void	stack_create_front(int value, t_stacks *hello)
{
	t_stak	*final_stack;

	final_stack = malloc(sizeof(t_stak));
	final_stack->value = value;
	final_stack->next = hello->a;
	hello->a = final_stack;
}

t_stak	*stak_last(t_stak *hello)
{
	while (hello->next)
		hello = hello->next;
	return (hello);
}
