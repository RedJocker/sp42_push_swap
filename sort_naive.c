/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_naive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:20:41 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/03 03:17:00 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "two_stks.h"
#include "ft_util.h"
#include "limits.h"
#include "stat.h"

void	swap_a_maybe_b(t_two_stks *stks, int *blimit)
{
	int		*curr[2]; 
	
	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_next(stks->b);
	if (curr[0] && curr[1] && *curr[0] < *curr[1])
	{
			ss(stks);
			if (blimit && blimit[0] != 0 && blimit[1] == *curr[0])
			blimit[1] = *((int*)ft_stack_peek(stks->b));
	}
	else
		sa(stks);
}

void	swap_b_maybe_a(t_two_stks *stks, int *alimit)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_next(stks->a);
	if (curr[0] && curr[1] && *curr[0] > *curr[1])
	{
			ss(stks);
			if (alimit && alimit[0] != 0 && alimit[1] == *curr[0])
			alimit[1] = *((int*)ft_stack_peek(stks->a));
	}
	else
		sb(stks);
}

void	rotate_b_maybe_a(t_two_stks *stks, int *alimit)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_last(stks->a);
	if (curr[0] && curr[1] && *curr[0] > *curr[1])
	{
		rr(stks);
		if (alimit && alimit[0] != 0 && alimit[1] == *curr[0])
			alimit[1] = *((int*)ft_stack_peek(stks->a));
	}
	else
		rb(stks);
}

void	rotate_a_maybe_b(t_two_stks *stks, int *blimit)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_last(stks->b);
	if (curr[0] && curr[1] && *curr[0] < *curr[1])
	{
		rr(stks);
		if (blimit && blimit[0] != 0 && blimit[1] == *curr[0])
			blimit[1] = *((int*)ft_stack_peek(stks->b));
	}
	ra(stks);
}

void	push_b_and_check(t_two_stks *stks, int *alimit)
{
	int		*curr[2]; 

	pb(stks);
	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_last(stks->b);
	if (curr[1] && *curr[0] < *curr[1])
		return (rotate_b_maybe_a(stks, alimit));
	curr[1] = (int *) ft_stack_peek_next(stks->b);
	if (curr[1] && *curr[0] < *curr[1])
		return (swap_b_maybe_a(stks, alimit));
}


void	push_a_and_check(t_two_stks *stks, int *blimit)
{
	int		*curr[2]; 

	pa(stks);
	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_last(stks->a);
	if (curr[1] && *curr[0] > *curr[1])
		return (rotate_a_maybe_b(stks, blimit));
	curr[1] = (int *) ft_stack_peek_next(stks->a);
	if (curr[1] && *curr[0] > *curr[1])
		return (swap_a_maybe_b(stks, blimit));
}

void	sort_less_than4(t_two_stks *stks, t_stat *stat, int **curr)
{
	stat->is_sorted = 1;
	if (stat->len == 2)
		return (swap_a_maybe_b(stks, 0));
	curr[0] = ft_stack_peek(stks->a);
	curr[1] = ft_stack_peek_last(stks->a);
	if (*curr[0] == stat->min)
		return (swap_a_maybe_b(stks, 0), rotate_a_maybe_b(stks, 0));
	if (*curr[0] == stat->max && *curr[1] == stat->min)
		return (swap_a_maybe_b(stks, 0), rra(stks));
	if (*curr[0] == stat->max)
		return (rotate_a_maybe_b(stks, 0));
	if (*curr[1] == stat->max)
		return (swap_a_maybe_b(stks, 0));
	return (rra(stks));
}


void	process_stacka(t_two_stks *stks, t_stat *stat)
{
	int		*curr[2];
	int		limit[2];

	ft_puterrl("processing StackA");
	while (!stat->is_sorted && stat->len > 3)
	{
		limit[0] = 0;
		limit[1] = *((int *) ft_stack_peek_last(stks->a));
		curr[0] = (int *) ft_stack_peek(stks->a);
		while (*curr[0] != limit[1])
		{
			if (*curr[0] <= (int) stat->avg)
			{
				curr[1] = ft_stack_peek_next(stks->a);
				if (*curr[1] < *curr[0])
					swap_a_maybe_b(stks, 0);
				else
					push_b_and_check(stks, limit);
			}
			else
			{
				rotate_a_maybe_b(stks, 0);
				if (limit[0] == 0)
				{
					limit[1] = *((int *) ft_stack_peek_last(stks->a));
					limit[0] = limit[1] > stat->avg;
					ft_puterr("limit ");
					ft_int_printerr(limit + 0);
					ft_puterr(" ");
					ft_int_printerr(limit + 1);
					ft_puterrl("");
				}
			}
			two_stks_print(stks);
			curr[0] = (int *) ft_stack_peek(stks->a);
		}
		stat_init(stat);
		stat_compute(stat, stks->a);
		stat_print(stat);
	}
	if (!stat->is_sorted)
	{
		sort_less_than4(stks, stat, curr);
		two_stks_print(stks);
	}
}

void	process_stackb(t_two_stks *stks, t_stat *stat)
{
	int		*curr[2];
	int		limit[2];

	ft_puterrl("processing StackB");
	stat_init(stat);
	stat_compute(stat, stks->b);
	stat_print(stat);
	while (!stat->is_revsorted)
	{
		limit[0] = 0;
		limit[1] = *((int *)ft_stack_peek_last(stks->b));
		curr[0] = (int *) ft_stack_peek(stks->b);
		while (*curr[0] != limit[1])
		{
			if (*curr[0] >= (int) stat->avg)
			{
				curr[1] = ft_stack_peek_next(stks->b);
				if (*curr[1] > *curr[0])
					swap_b_maybe_a(stks, NULL);
				else
					push_a_and_check(stks, limit);
			}
			else
			{
				rotate_b_maybe_a(stks, NULL);
				if (limit[0] == 0)
				{
					limit[1] = *((int *) ft_stack_peek_last(stks->b));
					limit[0] = limit[1] < stat->avg;
					ft_puterr("limit ");
					ft_int_printerr(limit + 0);
					ft_puterr(" ");
					ft_int_printerr(limit + 1);
					ft_puterrl("");
				}
			}
			two_stks_print(stks);
			curr[0] = (int *) ft_stack_peek(stks->b);
		}
		stat_init(stat);
		stat_compute(stat, stks->b);
		stat_print(stat);
	}
	two_stks_print(stks);
}
	
void	two_stcks_sort_naive(t_two_stks *stks)
{
	t_stat	stat[2];

	two_stks_print(stks);
	stat_init(stat + 0);
	stat_compute(stat + 0, stks->a);
	stat_print(stat + 0);
	while (!stat[0].is_sorted)
	{
		process_stacka(stks, stat + 0);
		process_stackb(stks, stat + 1);
		if (stat[0].is_sorted && stat[1].is_revsorted)
		{
			while (ft_stack_len(stks->b) > 0)
				pa(stks);
		}
		stat_init(stat + 0);
		stat_compute(stat + 0, stks->a);
		stat_print(stat + 0);
	}
	ft_puterrl("Finish");
	two_stks_print(stks);
}
