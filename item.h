/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:33:50 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/10 15:35:31 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_H
# define ITEM_H

#include "stat3b.h"

int item_lower(int *item, t_stat3b *stat);
int item_middle(int *item, t_stat3b *stat);
int item_higher(int *item, t_stat3b *stat);
void item_count_not_high(int *item, t_stat3b *stat, int bound[2]);

#endif
