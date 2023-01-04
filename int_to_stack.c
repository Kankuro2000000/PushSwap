/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:46:21 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:46:52 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*int_to_stacks(int *array, int len)
{
	t_stacks	*hello;

	hello = stack_create(array[len - 1]);
	if (!hello)
		return (NULL);
	len--;
	while (len > 0)
	{
		stack_create_front(array[len - 1], hello);
		if (!hello)
			return (NULL);
		len--;
	}
	return (hello);
}

int	int_len(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i - 1);
}

int	check_argc(int argc, char **argv)
{
	if (argc == 1)
		exit (1);
	if (check_valid(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
		return (1);
	return (0);
}
