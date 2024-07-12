/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b_e4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:06:36 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/12 14:46:53 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort3b.h"
#include "stat3b.h"

static void	sort3_e4_maybe_swap_a_maybe_b(t_two_stks *stks, int **item)
{
	item[0] = ft_stack_peek(stks->a);
	item[1] = ft_stack_peek_next(stks->a);
	if (item[1] && *item[0] > *item[1])
		swap_a_maybe_b(stks);
}

static void	sort3_e4_proccess_stka(t_two_stks *stks, int **item)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		item[0] = ft_stack_peek(stks->a);
		item[1] = ft_stack_peek_next(stks->a);
		if (item[1] && *item[0] > *item[1])
		{
			swap_a_maybe_b(stks);
			continue ;
		}
		else
		{
			pb(stks);
			item[1] = ft_stack_peek_next(stks->b);
			item[2] = ft_stack_peek_last(stks->b);
			if (item[2] && *item[0] < *item[2])
				rb(stks);
			else if (item[1] && *item[0] < *item[1])
				swap_b_maybe_a(stks);
		}
		i++;
	}
	sort3_e4_maybe_swap_a_maybe_b(stks, item);
}

static void	sort3_e4_proccess_stkb(t_two_stks *stks, int **item)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		item[0] = ft_stack_peek(stks->b);
		item[1] = ft_stack_peek_next(stks->b);
		if (item[1] && *item[0] < *item[1])
		{
			swap_b_maybe_a(stks);
			continue ;
		}
		else
		{
			pa(stks);
			item[0] = ft_stack_peek(stks->a);
			item[1] = ft_stack_peek_next(stks->a);
			if (item[1] && *item[0] > *item[1])
				swap_a_maybe_b(stks);
		}
		i++;
	}
}

static void	sort3_e4_call_sort3(t_two_stks *stks, int min, int max)
{
	t_stat3b	stat_new;
	int			bound[2];

	bound[0] = min;
	bound[1] = max;
	stat3b_compute(&stat_new, stks->a, bound);
	if (!stat_new.is_sorted)
		sort3_e3(stks, &stat_new);
}

void	sort3_e4(t_two_stks *stks, t_stat3b *stat)
{
	int	*item[3];

	item[0] = ft_stack_peek(stks->a);
	item[1] = ft_stack_peek_next(stks->a);
	if (item[0] && *item[0] == stat->min)
	{
		pb(stks);
		sort3_e4_call_sort3(stks, stat->min + 1, stat->max);
		pa(stks);
	}
	else if (item[0] && item[1] && *item[1] == stat->min)
	{
		swap_a_maybe_b(stks);
		pb(stks);
		sort3_e4_call_sort3(stks, stat->min + 1, stat->max);
		pa(stks);
	}
	else
	{
		sort3_e4_proccess_stka(stks, item);
		sort3_e4_proccess_stkb(stks, item);
	}
}
