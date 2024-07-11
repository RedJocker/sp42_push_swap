/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:13:31 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 19:34:54 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "two_stks.h"
#include "stat3b.h"
#include <limits.h>
#include "sort3b.h"

void	swap_a_maybe_b(t_two_stks *stks)
{
	int	*curr[2];

	curr[0] = (int *) ft_stack_peek(stks->b);
	curr[1] = (int *) ft_stack_peek_next(stks->b);
	if (curr[0] && curr[1] && *curr[0] < *curr[1])
		ss(stks);
	else
		sa(stks);
}

void	swap_b_maybe_a(t_two_stks *stks)
{
	int	*curr[2];

	curr[0] = (int *) ft_stack_peek(stks->a);
	curr[1] = (int *) ft_stack_peek_next(stks->a);
	if (curr[0] && curr[1] && *curr[0] > *curr[1])
		ss(stks);
	else
		sb(stks);
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
