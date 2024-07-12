/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b_partition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:11:27 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/12 12:52:54 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "collection/ft_arraylist.h"
#include "two_stks.h"
#include "stat3b.h"

static int	sort3b_partition_lower(t_two_stks *stks, t_stat3b *stat, int *item)
{
	int	*topa;
	int	*nextb;

	(void) item;
	stat->len_not_high--;
	pb(stks);
	nextb = ft_stack_peek_next(stks->b);
	topa = ft_stack_peek(stks->a);
	if (item_lower(nextb, stat))
		return (0);
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

static void	sort3b_partition_higher(t_two_stks *stks, t_stat3b *stat, int *item)
{
	int	*nexta;
	int	*nnexta;
	int	*topb;
	int	*nextb;

	(void) item;
	nexta = ft_stack_peek_next(stks->a);
	nextb = ft_stack_peek_next(stks->b);
	topb = ft_stack_peek(stks->b);
	nnexta = ft_arraylist_get(stks->a, 2);
	if (nextb && topb && item_lower(nexta, stat)
		&& *nextb > *topb && !item_higher(nnexta, stat))
		ss(stks);
	else
		ra(stks);
}

static void	sort3b_partition_middle(t_two_stks *stks, t_stat3b *stat, int *item)
{
	(void) item;
	stat->len_not_high--;
	pb(stks);
}

void	sort3b_partition(t_two_stks *stks, t_stat3b *stat)
{
	int	*item;
	int	was_last_rotated;

	was_last_rotated = 0;
	while (stat->len_not_high >= 0)
	{
		item = ft_stack_peek(stks->a);
		if (item_lower(item, stat))
			was_last_rotated = sort3b_partition_lower(stks, stat, item);
		else if (item_middle(item, stat))
			sort3b_partition_middle(stks, stat, item);
		else if (item_higher(item, stat))
			sort3b_partition_higher(stks, stat, item);
		else
			break ;
		if (item == stat->last || was_last_rotated)
			break ;
	}
}
