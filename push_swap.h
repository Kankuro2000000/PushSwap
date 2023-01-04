/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:19:59 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/03 13:20:06 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <inttypes.h>
# include <unistd.h>
# include <stdio.h>

typedef struct stak {
	int			value;
	int			right;	
	int			back;
	int			place;
	struct stak	*next;
}	t_stak;

typedef struct stacks {
	int		min;
	int		mid;
	int		max;
	t_stak	*a;
	t_stak	*b;
}	t_stacks;

int			ft_strcmp(char *s1, char *s2);
int			check_duplic(int argc, char **argv);
int64_t		ft_atoi(char *str);
int			check_int(int argc, char **argv);
int			check_alfa(int argc, char **argv);
int			check_valid(int argc, char **argv);
int			ft_strlen(char *str);
void		map_to_int(int *map_int, char **map);
int			*malloc_array(char **map);
int			check_sort(int *array, int len);
void		sort_array(int *array, int len);
void		min_mid_max(int *array, int len, t_stacks *hello);
t_stacks	*stack_create(int value);
void		stack_create_front(int value, t_stacks *hello);
t_stak		*stak_last(t_stak *hello);
void		swap_a(t_stacks *hello);
void		swap_b(t_stacks *hello);
void		swap_ss(t_stacks *hello);
void		push_a(t_stacks *hello);
void		push_b(t_stacks *hello);
void		rotate_a(t_stacks *hello);
void		rotate_b(t_stacks *hello);
void		rotate(t_stacks *hello);
void		rev_rotate_a(t_stacks *hello);
void		rev_rotate_b(t_stacks *hello);
void		rev_rotate(t_stacks *hello);
void		find_right(t_stacks *hello);
void		find_back_a(t_stacks *hello);
void		find_back_b(t_stacks *hello);
void		start_sort(t_stacks *hello);
int			find_min(t_stak *buff);
void		find_cost_place(t_stacks *hello);
t_stak		*find_best_move(t_stak *buff);
t_stak		*find_good_place(t_stak *buff, t_stak *best_move);
void		move_a(t_stacks *hello, t_stak *good_place);
void		move_b(t_stacks *hello, t_stak *best_move);
void		main_sort(t_stacks *hello);
void		check_stack_sort(t_stacks *hello);
void		last_chance_rotate(t_stak *buff, t_stacks *hello);
void		last_chance_rev_rotate(t_stak *buff, t_stacks *hello);
void		last_chance(t_stacks *hello, int min);
t_stacks	*int_to_stacks(int *array, int len);
int			int_len(char **map);
int			cost_place(t_stak *buff_a, t_stak *buff_b, t_stak *last_a);
void		act_before_sort(t_stacks *hello, int len, int *array);
void		sorting_process(t_stacks *hello);
int			array_sorted(int *array, int len, t_stacks *hello);
int			check_t_stacksort(t_stak *buff, t_stacks *hello);
void		act_for_5(t_stacks *hello, int count);
void		sort_3(t_stacks *hello);
void		free_stacks(t_stacks *hello);
int			check_argc(int argc, char **argv);

#endif
