/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:44:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/28 00:33:47 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "collection/ft_stack.h"
#include "ft_string.h"
#include "psargs.h"
#include "ft_stdio.h"
#include "two_stks.h"
#include "ft_util.h"
#include "limits.h"
#include "stat.h"



void	two_stcks_sort(t_two_stks *stks, t_consumer sort_impl)
{
	sort_impl(stks);
}

void	swap_a_maybe_b(t_two_stks *stks)
{
	int		*curr[2]; 
	
	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_next(stks->b);
	if (curr[0] && curr[1] && *curr[0] < *curr[1])
		ss(stks);
	else
		sa(stks);
}

void	swap_b_maybe_a(t_two_stks *stks)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_next(stks->a);
	if (curr[0] && curr[1] && *curr[0] > *curr[1])
		ss(stks);
	else
		sb(stks);
}

void	rotate_b_maybe_a(t_two_stks *stks)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_last(stks->a);
	if (curr[0] && curr[1] && *curr[0] > *curr[1])
		return (rr(stks));
	rb(stks);
}

void	rotate_a_maybe_b(t_two_stks *stks)
{
	int		*curr[2]; 

	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_last(stks->b);
	if (curr[0] && curr[1] && *curr[0] < *curr[1])
		return (rr(stks));
	ra(stks);
}


void	push_b_and_check(t_two_stks *stks)
{
	int		*curr[2]; 

	pb(stks);
	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_last(stks->b);
	if (curr[1] && *curr[0] < *curr[1])
		return (rotate_b_maybe_a(stks));
	curr[1] = (int *) ft_stack_peek_next(stks->b);
	ft_puterr("curr[1]: ");
	if (curr[1])	
		ft_putnbr_fd(*curr[1], 2);
	ft_puterr(" curr[0]: ");
	if (curr[0])
		ft_putnbr_fd(*curr[0], 2);
	ft_puterrl("");
	if (curr[1] && *curr[0] < *curr[1])
		return (swap_b_maybe_a(stks));
}


void	push_a_and_check(t_two_stks *stks)
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


void	process_stacka(t_two_stks *stks)
{
	t_stat	stat;
	int		*curr[2];
	int		limit[2];

	stat_init(&stat);
	stat_compute(&stat, stks->a);
	stat_print(&stat);
	limit[0] = 0;
	limit[1] = stat.last;
	while (ft_stack_len(stks->a) > 1)
	{
		curr[0] = (int *) ft_stack_peek(stks->a);
		while (*curr[0] != limit[1])
		{
			if (*curr[0] <= (int) stat.avg)
			{
				curr[1] = ft_stack_peek_next(stks->a);
				if (*curr[1] < *curr[0])
					swap_a_maybe_b(stks);
				else
					push_b_and_check(stks);
			}
			else
			{
				ra(stks);
				if (limit[0] == 0)
				{
					limit[0] = 1;
					limit[1] = *((int *) ft_stack_peek_last(stks->a));
				}
			}
			two_stks_print(stks);
			curr[0] = (int *) ft_stack_peek(stks->a);
		}
		stat_init(&stat);
		stat_compute(&stat, stks->a);
		stat_print(&stat);
		limit[0] = 0;
		limit[1] = stat.last;
	}
}

void	process_stackb(t_two_stks *stks)
{
	t_stat	stat;
	int		*curr[2];

	stat_init(&stat);
	stat_compute(&stat, stks->b);
	stat_print(&stat);
	while (ft_stack_len(stks->b) > 1)
	{
		curr[0] = (int *) ft_stack_peek(stks->b);
		while (*curr[0] != stat.last)
		{
			if (*curr[0] >= (int) stat.avg)
			{
				curr[1] = ft_stack_peek_next(stks->b);
				if (*curr[1] > *curr[0])
					swap_b_maybe_a(stks);
				else
					push_a_and_check(stks);
			}
			else
			{
				rb(stks);
			}
			two_stks_print(stks);
			curr[0] = (int *) ft_stack_peek(stks->b);
		}
		stat_init(&stat);
		stat_compute(&stat, stks->b);
		stat_print(&stat);
	}
	push_a_and_check(stks);
	two_stks_print(stks);
}
	
void	two_stcks_sort_naive(t_two_stks *stks)
{
	t_stat	stat;

	two_stks_print(stks);
	stat_init(&stat);
	stat_compute(&stat, stks->a);
	while (!stat.is_sorted)
	{
		process_stacka(stks);
		process_stackb(stks);
		stat_init(&stat);
		stat_compute(&stat, stks->a);
		stat_print(&stat);
	}
}

int	testable_main(int argc, char *argv[])
{
	t_psargs	psargs;
	int			is_parseok;
	t_two_stks	*stks;

	if (argc < 2)
		return (1);
	stks = two_stks_new();
	is_parseok = psargs_init(&psargs, argv + 1, argc - 1);
	if (is_parseok)
	{
		two_stks_init(stks, &psargs);
		two_stks_sort(stks, (t_consumer) two_stcks_sort_naive);
	}
	else
		ft_puterrl("Error");
	two_stks_destroy(stks);
	psargs_clean(&psargs);
	return (!is_parseok);
}
