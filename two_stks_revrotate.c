/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stks_revrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:50:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 19:51:44 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "two_stks.h"

void	stack_rev_rotate(t_stack stk)
{
	void	*elem;

	elem = ft_stack_pop_back(stk);
	stk = ft_stack_push(stk, elem);
}

void	rra(t_two_stks *stks)
{
	stack_rev_rotate(stks->a);
	ft_putendl("rra");
	ft_puterrl("rra");
}

void	rrb(t_two_stks *stks)
{
	stack_rev_rotate(stks->b);
	ft_putendl("rrb");
	ft_puterrl("rrb");
}

void	rrr(t_two_stks *stks)
{
	stack_rev_rotate(stks->a);
	stack_rev_rotate(stks->b);
	ft_putendl("rrr");
	ft_puterrl("rrr");
}
