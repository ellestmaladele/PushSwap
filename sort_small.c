/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_node *stack)
{
	int	position;
	int	min_index;
	int	i;

	position = 0;
	i = 0;
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

void	rotate_to_top(t_stacks *stacks, int position)
{
	int	size;

	size = stack_size(stacks->a);
	if (position <= size / 2)
	{
		while (position-- > 0)
			ra(stacks);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rra(stacks);
	}
}

static void	sort_three_nodes(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->a->index;
	second = stacks->a->next->index;
	third = stacks->a->next->next->index;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(stacks);
	else if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first > second && second < third && first > third)
		ra(stacks);
	else if (first < second && second > third && first < third)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (first < second && second > third && first > third)
		rra(stacks);
}

static void	sort_five_nodes(t_stacks *stacks)
{
	int	position;

	while (stack_size(stacks->a) > 3)
	{
		position = find_min_position(stacks->a);
		rotate_to_top(stacks, position);
		pb(stacks);
	}
	sort_three_nodes(stacks);
	while (stacks->b)
		pa(stacks);
}

void	sort_small(t_stacks *stacks)
{
	int	size;

	size = stack_size(stacks->a);
	if (size <= 1 || stack_sorted(stacks->a))
		return ;
	if (size == 2)
	{
		if (stacks->a->value > stacks->a->next->value)
			sa(stacks);
		return ;
	}
	if (size == 3)
		sort_three_nodes(stacks);
	else
		sort_five_nodes(stacks);
}
