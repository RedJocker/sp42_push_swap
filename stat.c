/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:25:36 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/07 14:12:37 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "limits.h"
#include "stat.h"
#include "ft_util.h"

void	stat_print(t_stat *stat)
{
	ft_puterr("\nmin: ");
	ft_putnbr_fd(stat->min, 2);
	ft_puterr("\nmax: ");
	ft_putnbr_fd(stat->max, 2);
	ft_puterr("\nlen: ");
	ft_putnbr_fd(stat->len, 2);
	ft_puterr("\nlast: ");
	ft_int_printerr(stat->last);
	ft_puterr("\nis_sorted: ");
	ft_putnbr_fd(stat->is_sorted, 2);
	ft_puterr("\nis_revsorted: ");
	ft_putnbr_fd(stat->is_revsorted, 2);
	ft_puterr("\navg: ");
	ft_putnbr_fd((int) stat->avg, 2);
	ft_puterr("\nfirst_sorted: ");
	ft_int_printerr(stat->first_sorted);
	ft_puterr("\nfirst_revsorted: ");
	ft_int_printerr(stat->first_revsorted);
	ft_puterr("\navg_nosorted: ");
	ft_putnbr_fd((int) stat->avg_nosorted, 2);
	ft_puterr("\navg_norevsorted: ");
	ft_putnbr_fd((int) stat->avg_norevsorted, 2);
	ft_puterr("\nlen_le_avg_nosorted: ");
	ft_putnbr_fd(stat->len_le_avg_nosorted, 2);
	ft_puterr("\nlen_ge_avg_norevsorted: ");
	ft_putnbr_fd(stat->len_ge_avg_norevsorted, 2);
	ft_puterrl("");
}

void	stat_init(t_stat *out_stat)
{
	out_stat->min = INT_MAX;
	out_stat->max = INT_MIN;
	out_stat->avg = 0;
	out_stat->last = NULL;
	out_stat->len = 0;
	out_stat->is_sorted = 1;
	out_stat->is_revsorted = 1;
	out_stat->first_sorted = 0;
	out_stat->first_revsorted = 0;
	out_stat->avg_nosorted = 0;
	out_stat->avg_norevsorted = 0;
	out_stat->len_le_avg_nosorted = 0;
	out_stat->len_ge_avg_norevsorted = 0;
}

void	stat_item_process(int *item, t_stat *stat)
{
	
	if (stat == NULL)
		return ;
	if (*item < stat->min)
	{
		stat->min = *item;
		if (!stat->first_revsorted)
			stat->first_revsorted = item;
	}
	else
		stat->first_revsorted = 0;
	if (*item > stat->max)
	{
		stat->max = *item;
		if (!stat->first_sorted)
			stat->first_sorted = item;
	}
	else
		stat->first_sorted = 0;
	stat->avg = (*item + (stat->len * stat->avg)) / (stat->len + 1);
	stat->is_sorted = !stat->last || (stat->is_sorted && *item > *stat->last);
	stat->is_revsorted = !stat->last || (stat->is_revsorted && *item < *stat->last);
	stat->last = item;
	stat->len++;
}

void	stat_item_improve_avg(int *item, t_stat *stat)
{
	
	if (stat == NULL || *item == stat->max || *item == stat->min)
		return ;
	if (stat->first_sorted && *item >= *stat->first_sorted)
	{
		stat->avg_nosorted = ((stat->len_le_avg_nosorted * stat->avg_nosorted)
							  - *item) / (stat->len_le_avg_nosorted - 1);
		stat->len_le_avg_nosorted--;
	}
	if (stat->first_revsorted && *item <= *stat->first_revsorted)
	{
		stat->avg_norevsorted = ((stat->len_ge_avg_norevsorted * stat->avg_norevsorted)
							  - *item) / (stat->len_ge_avg_norevsorted - 1);
		stat->len_ge_avg_norevsorted--;
	}
}


void	stat_item_len_avg(int *item, t_stat *stat)
{
	if (stat == NULL)
		return ;
	if (*item <= (int) stat->avg_nosorted)
	{
		stat->len_le_avg_nosorted++;
	}
	if (*item >= (int) stat->avg_norevsorted)
	{
		stat->len_ge_avg_norevsorted++;
	}
}

void	stat_compute(t_stat *stat, t_stack stk)
{
	stat_init(stat);
	ft_stack_foreacharg(stk, (t_biconsumer) stat_item_process, stat);
	if (stat->len <= 3)
		return ;
	stat->avg = ((stat->len * stat->avg) - stat->min) / (stat->len - 1);
	stat->avg = (
		((stat->len - 1) * stat->avg) - stat->max) / (stat->len - 2);
	stat->avg_nosorted = stat->avg;
	stat->avg_norevsorted = stat->avg;
	stat->len_le_avg_nosorted = stat->len - 2;
	stat->len_ge_avg_norevsorted = stat->len - 2;
	ft_stack_foreacharg(stk, (t_biconsumer) stat_item_improve_avg, stat);
	stat->len_le_avg_nosorted = 0;
	stat->len_ge_avg_norevsorted = 0;
	ft_stack_foreacharg(stk, (t_biconsumer) stat_item_len_avg, stat);
	stat_print(stat);
}
