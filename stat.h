/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:27:22 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/03 04:31:24 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAT_H
# define STAT_H

# include "collection/ft_stack.h"

typedef struct s_stat
{
	int		min;
	int		max;
	double	avg;
	int		*last;
	int		len;
	int		is_sorted;
	int		is_revsorted;
	int		*first_sorted;
	int		*first_revsorted;
	double	avg_nosorted;
	double	avg_norevsorted;
	int		len_le_avg_nosorted;
	int		len_ge_avg_norevsorted;
}	t_stat;

void	stat_init(t_stat *out_stat);
void	stat_item_process(int *item, t_stat *stat);
void	stat_compute(t_stat *out_stat, t_stack stk);
void	stat_print(t_stat *stat);

#endif
