/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b_le4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:26:42 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/12 13:25:16 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort3b.h"

static void	sort3b_e3_max(t_two_stks *stks, t_stat3b *stat, int *next)
{
	swap_a_maybe_b(stks);
	pb(stks);
	swap_a_maybe_b(stks);
	pa(stks);
	if (*next != stat->min)
		swap_a_maybe_b(stks);
}

void	sort3_e3(t_two_stks *stks, t_stat3b *stat)
{
	int	*item[2];

	item[0] = ft_stack_peek(stks->a);
	item[1] = ft_stack_peek_next(stks->a);
	if (*item[0] == stat->min)
	{
		pb(stks);
		swap_a_maybe_b(stks);
		pa(stks);
	}
	else if (*item[0] == stat->max)
		sort3b_e3_max(stks, stat, item[1]);
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

void	sort3_le4(t_two_stks *stks, t_stat3b *stat)
{
	if (stat->len == 2)
		swap_a_maybe_b(stks);
	else if (stat->len == 3)
		sort3_e3(stks, stat);
	else
		sort3_e4(stks, stat);
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
