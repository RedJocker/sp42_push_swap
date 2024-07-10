/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:31:38 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/10 16:02:47 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "item.h"

void	item_count_not_high(int *item, t_stat3b *stat, int bound[2])
{
	if (stat == NULL || *item < bound[0] || *item > bound[1])
		return ;
	if (!item_higher(item, stat))
		stat->len_not_high++;
}

int	item_higher(int *item, t_stat3b *stat)
{
	int	limit[2];

	if (item == NULL)
		return (0);
	limit[0] = (int)(stat->min + (2 * stat->mean3));
	limit[1] = (int)stat->max;
	return (*item >= limit[0] && *item <= limit[1]);
}

int	item_middle(int *item, t_stat3b *stat)
{
	int	limit[2];

	if (item == NULL)
		return (0);
	limit[0] = (int)(stat->min + stat->mean3);
	limit[1] = (int)(stat->min + (2 * stat->mean3)) - 1;
	return (*item >= limit[0] && *item <= limit[1]);
}

int	item_lower(int *item, t_stat3b *stat)
{
	int	limit[2];

	if (item == NULL)
		return (0);
	limit[0] = (int)(stat->min);
	limit[1] = (int)(stat->min + stat->mean3) - 1;
	return (*item >= limit[0] && *item <= limit[1]);
}
