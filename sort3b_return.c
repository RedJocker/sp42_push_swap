/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3b_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:19:48 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 20:53:47 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "sort3b.h"

void	sort3_return_a_middle(t_two_stks *stks, t_stat3b *stat)
{
	int	*current;

	current = ft_stack_peek(stks->b);
	while (item_middle(current, stat))
	{
		pa(stks);
		current = ft_stack_peek(stks->b);
	}
}

void	sort3_return_a_lower(t_two_stks *stks, t_stat3b *stat)
{
	int	*current;

	current = ft_stack_peek(stks->b);
	while (item_lower(current, stat))
	{
		pa(stks);
		current = ft_stack_peek(stks->b);
	}
	current = ft_stack_peek_last(stks->b);
	while (item_lower(current, stat))
	{
		rrb(stks);
		pa(stks);
		current = ft_stack_peek_last(stks->b);
	}
}

void	sort3_rotate_high(t_two_stks *stks, t_stat3b *stat)
{
	int	*top;
	int	*bottom;

	top = ft_stack_peek(stks->a);
	bottom = ft_stack_peek_last(stks->a);
	if (item_higher(top, stat) && item_higher(bottom, stat))
		return ;
	while (item_higher(bottom, stat))
	{
		rra(stks);
		bottom = ft_stack_peek_last(stks->a);
	}
}
