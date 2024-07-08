/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat3b.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:52:16 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/07 20:11:57 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STAT3B_H
# define STAT3B_H

# include "collection/ft_stack.h"

typedef struct s_stat3b
{
	int		min;
	int		max;
	double	avg;
	double	mean3;
	int		*last;
	int		len;
	int		is_sorted;
	int     is_revsorted;
	int		len_not_high;
	
}	t_stat3b;

void	stat3b_init(t_stat3b *out_stat);
void	stat3b_compute(t_stat3b *out_stat, t_stack stk, int bound[2]);
void	stat3b_print(t_stat3b *stat);
int		item_lower(int *item, t_stat3b *stat);
int		item_middle(int *item, t_stat3b *stat);
int		item_higher(int *item, t_stat3b *stat);

#endif
