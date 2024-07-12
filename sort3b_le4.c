/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b_le4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:26:42 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 20:52:41 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort3b.h"

static void	sort3_e3(t_two_stks *stks, t_stat3b *stat)
{
	int	*item[2];

	item[0] = ft_stack_peek(stks->a);
	item[1] = ft_stack_peek_next(stks->a);
	if (*item[0] == stat->min)
		(pb(stks), swap_a_maybe_b(stks), pa(stks));
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
			(pb(stks), swap_a_maybe_b(stks));
			(pa(stks), swap_a_maybe_b(stks));
		}
	}
}

static void	sort3_e4_proccess_stka(t_two_stks *stks, int **item)
{
	int	i;

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
}

static void	sort3_e4(t_two_stks *stks)
{
	int	*item[3];
	int	i;

	sort3_e4_proccess_stka(stks, item);
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
			pa(stks);
		i++;
	}
}

void	sort3_le4(t_two_stks *stks, t_stat3b *stat)
{
	if (stat->len == 2)
		swap_a_maybe_b(stks);
	else if (stat->len == 3)
		sort3_e3(stks, stat);
	else
		sort3_e4(stks);
}

void	sort3b_e3_wholestks(t_two_stks *stks, t_stat3b *stat)
{
	int	*curr[2];

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
