/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 04:41:46 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/07 15:40:33 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "two_stks.h"
#include "limits.h"
#include "stat.h"

static void	swap_a_maybe_b(t_two_stks *stks)
{
	int		*curr[2]; 
	
	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_next(stks->b);
	if (curr[0] && curr[1] && *curr[0] < *curr[1])
		ss(stks);
	else
		sa(stks);
}

static void	swap_b_maybe_a(t_two_stks *stks)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_next(stks->a);
	if (curr[0] && curr[1] && *curr[0] > *curr[1])
		ss(stks);
	else
		sb(stks);
}

static void	rotate_b_maybe_a(t_two_stks *stks)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_last(stks->a);
	if (curr[0] && curr[1] && *curr[0] > *curr[1])
		rr(stks);
	else
		rb(stks);
}

static void	rotate_a_maybe_b(t_two_stks *stks)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_last(stks->b);
	if (curr[0] && curr[1] && *curr[0] < *curr[1])
		rr(stks);
	else
		ra(stks);
}

static void	push_b_and_check(t_two_stks *stks)
{
	int		*curr[2]; 

	pb(stks);
	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_last(stks->b);
	if (curr[1] && *curr[0] < *curr[1])
		return (rotate_b_maybe_a(stks));
	curr[1] = (int *) ft_stack_peek_next(stks->b);
	if (curr[1] && *curr[0] < *curr[1])
		return (swap_b_maybe_a(stks));
}


static void	push_a_and_check(t_two_stks *stks)
{
	int		*curr[2]; 

	pa(stks);
	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_last(stks->a);
	if (curr[1] && *curr[0] > *curr[1])
		return (rotate_a_maybe_b(stks));
	curr[1] = (int *) ft_stack_peek_next(stks->a);
	if (curr[1] && *curr[0] > *curr[1])
		return (swap_a_maybe_b(stks));
}

static void	sort_less_than4(t_two_stks *stks, t_stat *stat, int **curr)
{
	stat->is_sorted = 1;
	if (stat->len == 2)
		return (swap_a_maybe_b(stks));
	curr[0] = ft_stack_peek(stks->a);
	curr[1] = ft_stack_peek_last(stks->a);
	if (*curr[0] == stat->min)
		return (swap_a_maybe_b(stks), rotate_a_maybe_b(stks));
	if (*curr[0] == stat->max && *curr[1] == stat->min)
		return (swap_a_maybe_b(stks), rra(stks));
	if (*curr[0] == stat->max)
		return (rotate_a_maybe_b(stks));
	if (*curr[1] == stat->max)
		return (swap_a_maybe_b(stks));
	return (rra(stks));
}

static void	revsort_less_than4(t_two_stks *stks, t_stat *stat, int **curr)
{
	stat->is_sorted = 1;
	if (stat->len == 2)
		return (swap_b_maybe_a(stks));
	curr[0] = ft_stack_peek(stks->b);
	curr[1] = ft_stack_peek_last(stks->b);
	if (*curr[0] == stat->max)
		return (swap_b_maybe_a(stks), rotate_b_maybe_a(stks));
	if (*curr[0] == stat->min && *curr[1] == stat->max)
		return (swap_b_maybe_a(stks), rrb(stks));
	if (*curr[0] == stat->min)
		return (rotate_b_maybe_a(stks));
	if (*curr[1] == stat->min)
		return (swap_b_maybe_a(stks));
	return (rrb(stks));
}


static void	process_stacka(t_two_stks *stks, t_stat *stat)
{
	int		*curr[2];

	ft_puterrl("processing StackA");
	while (!stat->is_sorted && stat->len > 3)
	{
		while (stat->len_le_avg_nosorted > 0)
		{
			curr[0] = (int *) ft_stack_peek(stks->a);
			if (*curr[0] <= (int) stat->avg_nosorted)
			{
				curr[1] = ft_stack_peek_next(stks->a);
				if (*curr[1] < *curr[0])
					swap_a_maybe_b(stks);
				else
				{
					push_b_and_check(stks);
					stat->len_le_avg_nosorted--;
				}
			}
			else
				rotate_a_maybe_b(stks);
			two_stks_print(stks);
		}
		curr[0] = ft_stack_peek_last(stks->a);
		while (stat->first_sorted && *curr[0] != stat->max)
		{
			rra(stks);
			curr[0] = ft_stack_peek_last(stks->a);
		}
		two_stks_print(stks);
		stat_compute(stat, stks->a);
	}
	if (!stat->is_sorted)
		sort_less_than4(stks, stat, curr);
	two_stks_print(stks);
}

static void	process_stackb(t_two_stks *stks, t_stat *stat)
{
	int		*curr[2];

	ft_puterrl("processing StackB");
	stat_compute(stat, stks->b);
	while (!stat->is_revsorted && stat->len > 3)
	{
		while (stat->len_ge_avg_norevsorted > 0)
		{
			curr[0] = ft_stack_peek(stks->b);
			if (*curr[0] >= (int) stat->avg_norevsorted)
			{
				curr[1] = ft_stack_peek_next(stks->b);
				if (*curr[1] > *curr[0])
					swap_b_maybe_a(stks);
					
				else
				{
					push_a_and_check(stks);
					stat->len_ge_avg_norevsorted--;
				}
			}
			else
			{
				rotate_b_maybe_a(stks);
			}
			two_stks_print(stks);
			ft_int_printerr(&stat->len_ge_avg_norevsorted);
		}
		curr[0] = ft_stack_peek_last(stks->b);
		while (stat->first_revsorted && *curr[0] != stat->min)
		{
			rrb(stks);
			curr[0] = ft_stack_peek_last(stks->b);
		}
		two_stks_print(stks);
		stat_compute(stat, stks->b);
	}
	if (!stat->is_revsorted)
		revsort_less_than4(stks, stat, curr);
	two_stks_print(stks);
}
	
void	two_stcks_sort_two(t_two_stks *stks)
{
	t_stat	stat[2];

	two_stks_print(stks);
	stat_compute(stat + 0, stks->a);
	while (!stat[0].is_sorted)
	{
		process_stacka(stks, stat + 0);
		process_stackb(stks, stat + 1);
		if (stat[0].is_sorted && stat[1].is_revsorted)
		{
			while (ft_stack_len(stks->b) > 0)
				pa(stks);
		}
		stat_compute(stat + 0, stks->a);
	}
	ft_puterrl("Finish");
	two_stks_print(stks);
}
