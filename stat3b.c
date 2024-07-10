/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat3b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:58:40 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/10 16:01:11 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "limits.h"
#include "stat3b.h"
#include "ft_util.h"
#include "item.h"

void	stat3b_print(t_stat3b *stat)
{
	ft_puterr("\nmin: ");
	ft_putnbr_fd(stat->min, 2);
	ft_puterr("\nmax: ");
	ft_putnbr_fd(stat->max, 2);
	ft_puterr("\nlen: ");
	ft_putnbr_fd(stat->len, 2);
	ft_puterr("\nlen_not_high: ");
	ft_putnbr_fd(stat->len_not_high, 2);
	ft_puterr("\nlast: ");
	ft_int_printerr(stat->last);
	ft_puterr("\nis_sorted: ");
	ft_putnbr_fd(stat->is_sorted, 2);
	ft_puterr("\nis_revsorted: ");
	ft_putnbr_fd(stat->is_revsorted, 2);
	ft_puterr("\navg: ");
	ft_putnbr_fd((int) stat->avg, 2);
	ft_puterr("\nmean3: ");
	ft_putnbr_fd((int) stat->mean3, 2);
	ft_puterrl("");
}

void	stat3b_init(t_stat3b *out_stat)
{
	out_stat->min = INT_MAX;
	out_stat->max = INT_MIN;
	out_stat->avg = 0;
	out_stat->last = NULL;
	out_stat->len = 0;
	out_stat->is_sorted = 1;
	out_stat->is_revsorted = 1;
	out_stat->mean3 = 0;
	out_stat->len_not_high = 0;
}

static void	stat3b_item_process(int *item, t_stat3b *stat, int bound[2])
{
	if (stat == NULL || *item < bound[0] || *item > bound[1])
		return ;
	if (*item < stat->min)
		stat->min = *item;
	if (*item > stat->max)
		stat->max = *item;
	stat->avg = (*item + (stat->len * stat->avg)) / (stat->len + 1);
	stat->is_sorted = !stat->last || (stat->is_sorted && *item > *stat->last);
	stat->is_revsorted = !stat->last
		|| (stat->is_revsorted && *item < *stat->last);
	stat->last = item;
	stat->len++;
}

void	stat3b_compute(t_stat3b *stat, t_stack stk, int bound[2])
{
	stat3b_init(stat);
	ft_stack_foreachbiarg(
		stk, (t_triconsumer) stat3b_item_process, stat, bound);
	stat->mean3 = (stat->len * stat->avg) / (3 * stat->avg);
	if (stat->len <= 2)
	{
		stat->avg = ((stat->len * stat->avg) - stat->min) / (stat->len - 1);
		stat->avg = (
				((stat->len - 1) * stat->avg) - stat->max) / (stat->len - 2);
	}
	stat->mean3 = (stat->len * stat->avg) / (3 * stat->avg);
	ft_stack_foreachbiarg(
		stk, (t_triconsumer) item_count_not_high, stat, bound);
	stat3b_print(stat);
}
