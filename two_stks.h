/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:47:43 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/19 22:14:11 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWO_STKS_H
# define TWO_STKS_H

# include "collection/ft_stack.h"

typedef struct s_two_stks
{
	t_stack	a;
	t_stack	b;
}	t_two_stks;

void		sa(t_two_stks *stks);
void		sb(t_two_stks *stks);
void		ss(t_two_stks *stks);
void		pa(t_two_stks *stks);
void		pb(t_two_stks *stks);
void		ra(t_two_stks *stks);
void		rb(t_two_stks *stks);
void		rr(t_two_stks *stks);
void		rra(t_two_stks *stks);
void		rrb(t_two_stks *stks);
void		rrr(t_two_stks *stks);
t_two_stks	*two_stks_new(void);
void		two_stks_destroy(t_two_stks *stks);
void		two_stks_print(t_two_stks *stks);

#endif
