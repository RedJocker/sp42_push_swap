/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:12:55 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/12 13:40:18 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT3B_H
# define SORT3B_H

# include "two_stks.h"
# include "stat3b.h"

void	sort3b_partition(t_two_stks *stks, t_stat3b *stat);
void	sort3b_sort(t_two_stks *stks, int bound[2]);
void	sort3_rotate_high(t_two_stks *stks, t_stat3b *stat);
void	sort3_return_a_lower(t_two_stks *stks, t_stat3b *stat);
void	sort3_return_a_middle(t_two_stks *stks, t_stat3b *stat);
void	swap_b_maybe_a(t_two_stks *stks);
void	swap_a_maybe_b(t_two_stks *stks);
void	sort3b_e3_wholestks(t_two_stks *stks, t_stat3b *stat);
void	sort3_le4(t_two_stks *stks, t_stat3b *stat);
void	sort3_e4(t_two_stks *stks, t_stat3b *stat);
void	sort3_e3(t_two_stks *stks, t_stat3b *stat);

#endif
