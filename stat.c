/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:25:36 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/29 17:24:43 by maurodri         ###   ########.fr       */
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
}

// avg calculation section5
// on https://jrsinclair.com/articles/2019/five-ways-to-average-with-js-reduce/ 
void	stat_item_process(int *item, t_stat *stat)
{
	
	if (stat == NULL)
		return ;
	if (*item < stat->min)
		stat->min = *item;
	if (*item > stat->max)
		stat->max = *item;
	stat->avg = (*item + (stat->len * stat->avg)) / (stat->len + 1);
	stat->is_sorted = !stat->last || (stat->is_sorted && *item > *stat->last);
	stat->is_revsorted = !stat->last || (stat->is_revsorted && *item < *stat->last);
	stat->last = item;
	stat->len++;
}

void	stat_compute(t_stat *out_stat, t_stack stk)
{
	ft_stack_foreacharg(stk, (t_biconsumer) stat_item_process, out_stat);
}
