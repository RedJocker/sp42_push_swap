/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stks_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:49:33 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 19:50:13 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "two_stks.h"

static void	stack_rotate(t_stack stk)
{
	void	*elem;

	elem = ft_stack_pop(stk);
	stk = ft_stack_push_back(stk, elem);
}

void	ra(t_two_stks *stks)
{
	stack_rotate(stks->a);
	ft_putendl("ra");
	ft_puterrl("ra");
}

void	rb(t_two_stks *stks)
{
	stack_rotate(stks->b);
	ft_putendl("rb");
	ft_puterrl("rb");
}

void	rr(t_two_stks *stks)
{
	stack_rotate(stks->a);
	stack_rotate(stks->b);
	ft_putendl("rr");
	ft_puterrl("rr");
}
