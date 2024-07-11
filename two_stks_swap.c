/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stks_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:46:26 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 19:47:44 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "two_stks.h"

static void	stack_swap(t_stack stk)
{
	void	*elem0;
	void	*elem1;

	elem0 = ft_stack_pop(stk);
	elem1 = ft_stack_pop(stk);
	stk = ft_stack_push(stk, elem0);
	stk = ft_stack_push(stk, elem1);
}

void	sa(t_two_stks *stks)
{
	stack_swap(stks->a);
	ft_putendl("sa");
	ft_puterrl("sa");
}

void	sb(t_two_stks *stks)
{
	stack_swap(stks->b);
	ft_putendl("sb");
	ft_puterrl("sb");
}

void	ss(t_two_stks *stks)
{
	stack_swap(stks->a);
	stack_swap(stks->b);
	ft_putendl("ss");
	ft_puterrl("ss");
}
