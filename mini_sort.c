/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_two(t_stacks *stacks)
{
	if (stacks->a->value > stacks->a->next->value)
		sa(stacks);
}

void	sort_three(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->a->value;
	second = stacks->a->next->value;
	third = stacks->a->next->next->value;
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

void	sort_four(t_stacks *stacks)
{
	move_min_to_top(stacks);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

void	sort_five(t_stacks *stacks)
{
	move_min_to_top(stacks);
	pb(stacks);
	move_min_to_top(stacks);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
	pa(stacks);
}

void	mini_sort(t_stacks *stacks)
{
	int	size;

	size = stack_size(stacks->a);
	if (is_sorted(stacks->a))
		return ;
	if (size == 2)
		sort_two(stacks);
	else if (size == 3)
		sort_three(stacks);
	else if (size == 4)
		sort_four(stacks);
	else if (size == 5)
		sort_five(stacks);
}
