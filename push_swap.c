/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:52:35 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 12:52:45 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_before_sort(t_stacks *hello, int len, int *array)
{
	sort_array(array, len);
	min_mid_max(array, len, hello);
	find_right(hello);
	find_back_a(hello);
	start_sort(hello);
	check_stack_sort(hello);
}

void	sorting_process(t_stacks *hello)
{
	find_right(hello);
	find_back_a(hello);
	find_back_b(hello);
	find_cost_place(hello);
	main_sort(hello);
}

int	array_sorted(int *array, int len, t_stacks *hello)
{
	sort_array(array, len);
	min_mid_max(array, len, hello);
	last_chance(hello, hello->min);
	return (0);
}

void	free_stacks(t_stacks *hello)
{
	t_stak	*tmp;
	t_stak	*buff;

	buff = hello->a;
	while (buff)
	{
		tmp = buff;
		buff = buff->next;
		free(tmp);
	}
	free(hello);
	hello = NULL;
}

int	main(int argc, char **argv)
{
	t_stacks	*hello;
	int			*array;
	int			len;

	if (check_argc(argc, argv))
		return (0);
	array = malloc_array(argv);
	if (!array)
		return (0);
	len = int_len(argv);
	hello = int_to_stacks(array, len);
	if (!hello)
		return (0);
	if (len == 3 && !check_sort(array, len))
		sort_3(hello);
	if (check_sort(array, len))
		return (array_sorted(array, len, hello));
	act_before_sort(hello, len, array);
	free(array);
	while (hello->b)
		sorting_process(hello);
	last_chance(hello, hello->min);
	free_stacks(hello);
	return (0);
}
