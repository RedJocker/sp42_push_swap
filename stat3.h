/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat3.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 07:07:55 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/06 07:19:19 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAT3_H
# define STAT3_H

# include "collection/ft_stack.h"

typedef struct s_stat3
{
	int		min;
	int		max;
	double	avg;
	double	mean3;
	int		*last;
	int		len;
	int		is_sorted;
	int		is_revsorted;
	
}	t_stat3;

void	stat3_init(t_stat3 *out_stat);
void	stat3_compute(t_stat3 *out_stat, t_stack stk, int bound[2]);
void	stat3_print(t_stat3 *stat);


#endif
