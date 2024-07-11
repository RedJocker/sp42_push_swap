/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:13:31 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 02:24:51 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "two_stks.h"
#include "stat3b.h"
#include <limits.h>

static void	swap_a_maybe_b(t_two_stks *stks)
{
	int	*curr[2];

	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_next(stks->b);
	if (curr[0] && curr[1] && *curr[0] < *curr[1])
		ss(stks);
	else
		sa(stks);
}

static void	swap_b_maybe_a(t_two_stks *stks)
{
	int	*curr[2];

	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_next(stks->a);
	if (curr[0] && curr[1] && *curr[0] > *curr[1])
		ss(stks);
	else
		sb(stks);
}

static void	sort3_e3(t_two_stks *stks, t_stat3b *stat)
{
	int	*item[2];

	ft_puterrl("e3");
	item[0] = ft_stack_peek(stks->a);
	item[1] = ft_stack_peek_next(stks->a);
	if (*item[0] == stat->min)
	{
		pb(stks);
		swap_a_maybe_b(stks);
		pa(stks);
	}
	else if (*item[0] == stat->max)
	{
		swap_a_maybe_b(stks);
		pb(stks);
		swap_a_maybe_b(stks);
		pa(stks);
		if (*item[1] != stat->min)
			swap_a_maybe_b(stks);
	}
	else
	{
		if (*item[1] == stat->min)
			swap_a_maybe_b(stks);
		else
		{
			pb(stks);
			swap_a_maybe_b(stks);
			pa(stks);
			swap_a_maybe_b(stks);
		}
	}
}

static void	sort3_e4(t_two_stks *stks)
{
	int	*item[3];
	int	i;

	ft_puterrl("e4");
	i = 0;
	while (i < 4)
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
	i = 0;
	while (i < 4)
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
		}
		i++;
	}
}

static void	sort3_le4(t_two_stks *stks, t_stat3b *stat)
{
	ft_puterrl("sort3_le4");
	if (stat->len == 2)
		swap_a_maybe_b(stks);
	else if (stat->len == 3)
		sort3_e3(stks, stat);
	else
		sort3_e4(stks);
}

static void	sort3_return_a_middle(t_two_stks *stks, t_stat3b *stat)
{
	int	*current;

	ft_puterrl("return_a_middle");
	stat3b_print(stat);
	current = ft_stack_peek(stks->b);
	while (item_middle(current, stat))
	{
		pa(stks);
		current = ft_stack_peek(stks->b);
	}
}

static void	sort3_return_a_lower(t_two_stks *stks, t_stat3b *stat)
{
	int	*current;

	ft_puterrl("return_a_lower");
	stat3b_print(stat);
	current = ft_stack_peek(stks->b);
	while (item_lower(current, stat))
	{
		pa(stks);
		current = ft_stack_peek(stks->b);
	}
	current = ft_stack_peek_last(stks->b);
	while (item_lower(current, stat))
	{
		rrb(stks);
		pa(stks);
		current = ft_stack_peek_last(stks->b);
	}
}

static int	sort3_fst_pos_lower(t_two_stks *stks, t_stat3b *stat, int *item)
{
	int	*topa;

	ft_puterrl("lower");
	(void) item;
	(void) stat;
	stat->len_not_high--;
	pb(stks);
	topa = ft_stack_peek(stks->a);
	if (item_higher(topa, stat))
	{
		rr(stks);
		return (topa == stat->last);
	}
	else
	{
		rb(stks);
		return (0);
	}
}

static void	sort3_fst_pos_higher(t_two_stks *stks, t_stat3b *stat, int *item)
{
	ft_puterrl("higher");
	(void) item;
	(void) stat;
	ra(stks);
}

static void	sort3_fst_pos_middle(t_two_stks *stks, t_stat3b *stat, int *item)
{
	ft_puterrl("middle");
	(void) item;
	stat->len_not_high--;
	pb(stks);
}

static void	sort3b_partition(t_two_stks *stks, t_stat3b *stat)
{
	int	*item;
	int	was_last_rotated;

	ft_puterrl("partition");
	was_last_rotated = 0;
	while (stat->len_not_high >= 0)
	{
		item = ft_stack_peek(stks->a);
		ft_puterr("item ");
		ft_int_printerr(item);
		ft_puterrl("");
		if (item_lower(item, stat))
			was_last_rotated = sort3_fst_pos_lower(stks, stat, item);
		else if (item_middle(item, stat))
			sort3_fst_pos_middle(stks, stat, item);
		else if (item_higher(item, stat))
			sort3_fst_pos_higher(stks, stat, item);
		else
		{
			ft_puterrl("break1");
			break ;
		}
		if (item == stat->last || was_last_rotated)
		{
			ft_puterrl("break last");
			break ;
		}
	}
}

static void	sort3_rotate_high(t_two_stks *stks, t_stat3b *stat)
{
	int	*top;
	int	*bottom;

	ft_puterrl("rotate_high");
	top = ft_stack_peek(stks->a);
	bottom = ft_stack_peek_last(stks->a);
	if (item_higher(top, stat) && item_higher(bottom, stat))
		return ;
	while (item_higher(bottom, stat))
	{
		rra(stks);
		bottom = ft_stack_peek_last(stks->a);
	}
}

static void	sort3b_e3_wholestks(t_two_stks *stks, t_stat3b *stat)
{
	int	*curr[2];

	ft_puterrl("e3_wholestks");
	curr[0] = ft_stack_peek(stks->a);
	curr[1] = ft_stack_peek_last(stks->a);
	if (*curr[0] == stat->min)
	{
		sa(stks);
		return (ra(stks));
	}
	if (*curr[0] == stat->max && *curr[1] == stat->min)
	{
		sa(stks);
		return (rra(stks));
	}
	if (*curr[0] == stat->max)
		return (ra(stks));
	if (*curr[1] == stat->max)
		return (sa(stks));
	return (rra(stks));
}

void	sort3b_sort(t_two_stks *stks, int bound[2])
{
	t_stat3b	stat;
	int			partition[2];

	stat3b_compute(&stat, stks->a, bound);
	two_stks_print(stks);
	if (stat.is_sorted)
		return ;
	if (stat.len == 3 && bound[0] == INT_MIN && bound[1] == INT_MAX)
		return (sort3b_e3_wholestks(stks, &stat));
	if (stat.len <= 4)
		return (sort3_le4(stks, &stat));
	sort3b_partition(stks, &stat);
	two_stks_print(stks);
	sort3_rotate_high(stks, &stat);
	partition[0] = stat.min + (2 * stat.mean3);
	partition[1] = stat.max;
	sort3b_sort(stks, partition);
	sort3_return_a_middle(stks, &stat);
	partition[1] = partition[0] - 1;
	partition[0] = stat.min + (stat.mean3);
	sort3b_sort(stks, partition);
	sort3_return_a_lower(stks, &stat);
	partition[1] = partition[0] - 1;
	partition[0] = stat.min;
	sort3b_sort(stks, partition);
}
