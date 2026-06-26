/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/26 09:03:43 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flags(int argc, char **argv, t_config *cfg)
{
	int	i;

	i = 1;
	while (i < argc && parse_flag(argv[i], cfg))
		i++;
	return (i);
}

static void	run_bench_mode(t_stack **a, t_stack **b, t_config *cfg)
{
	t_bench	bench;
	int		size;

	bench = (t_bench){0};
	g_bench = &bench;
	size = stack_size(*a);
	cfg->disorder = compute_disorder(*a);
	if (cfg->strategy == ADAPTIVE)
		adaptive_sort(a, b, cfg);
	else
		run_strategy(a, b, cfg);
	print_bench(cfg, &bench, size);
	g_bench = NULL;
}

static void	run_normal_mode(t_stack **a, t_stack **b, t_config *cfg)
{
	g_bench = NULL;
	cfg->disorder = compute_disorder(*a);
	if (cfg->strategy == ADAPTIVE)
		adaptive_sort(a, b, cfg);
	else
		run_strategy(a, b, cfg);
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	t_config	cfg;
	int			start;

	init_config(&cfg);
	start = parse_flags(argc, argv, &cfg);
	if (start >= argc)
		return (0);
	a = parse_arguments(argc - start + 1, argv + start - 1);
	b = NULL;
	if (!a)
		return (0);
	assign_indices(a);
	if (!stack_sorted(a))
	{
		if (cfg.bench)
			run_bench_mode(&a, &b, &cfg);
		else
			run_normal_mode(&a, &b, &cfg);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
