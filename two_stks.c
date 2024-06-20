/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:46:38 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/19 22:12:39 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "two_stks.h"
#include <stdlib.h>

t_two_stks	*two_stks_new(void)
{
	t_two_stks	*stks;

	stks = malloc(sizeof(t_two_stks));
	stks->a = ft_stack_new((t_consumer) ft_nop);
	stks->b = ft_stack_new((t_consumer) ft_nop);
	return (stks);
}

void	two_stks_destroy(t_two_stks *stks)
{
	ft_stack_destroy(stks->a);
	ft_stack_destroy(stks->b);
	free(stks);
}

void	two_stks_print(t_two_stks *stks)
{
	ft_putstr("A::");
	ft_stack_print(stks->a, (t_consumer) ft_int_print);
	ft_putstr("B::");
	ft_stack_print(stks->b, (t_consumer) ft_int_print);
}

// swap a
void	sa(t_two_stks *stks)
{
	void	*elem0;
	void	*elem1;

	if (ft_stack_len(stks->a) < 2)
		return ;
	elem0 = ft_stack_pop(stks->a);
	elem1 = ft_stack_pop(stks->a);
	stks->a = ft_stack_push(stks->a, elem0);
	stks->a = ft_stack_push(stks->a, elem1);
}

// swap b
void	sb(t_two_stks *stks)
{
	void	*elem0;
	void	*elem1;

	if (ft_stack_len(stks->b) < 2)
		return ;
	elem0 = ft_stack_pop(stks->b);
	elem1 = ft_stack_pop(stks->b);
	stks->b = ft_stack_push(stks->b, elem0);
	stks->b = ft_stack_push(stks->b, elem1);
}

// swap a and b
void	ss(t_two_stks *stks)
{
	sa(stks);
	sb(stks);
}

// push a
void	pa(t_two_stks *stks)
{
	void	*elem;

	if (ft_stack_len(stks->b) < 1)
		return ;
	elem = ft_stack_pop(stks->b);
	stks->a = ft_stack_push(stks->a, elem);
}

// push b
void	pb(t_two_stks *stks)
{
	void	*elem;

	if (ft_stack_len(stks->a) < 1)
		return ;
	elem = ft_stack_pop(stks->a);
	stks->b = ft_stack_push(stks->b, elem);
}

// rotate a
void	ra(t_two_stks *stks)
{
	void	*elem;

	if (ft_stack_len(stks->a) < 1)
		return ;
	elem = ft_stack_pop(stks->a);
	stks->a = ft_stack_push_back(stks->a, elem);
}

// rotate b
void	rb(t_two_stks *stks)
{
	void	*elem;

	if (ft_stack_len(stks->b) < 1)
		return ;
	elem = ft_stack_pop(stks->b);
	stks->b = ft_stack_push_back(stks->b, elem);
}

// rotate a and b
void	rr(t_two_stks *stks)
{
	ra(stks);
	rb(stks);
}

// reverse rotate a
void	rra(t_two_stks *stks)
{
	void	*elem;

	if (ft_stack_len(stks->a) < 1)
		return ;
	elem = ft_stack_pop_back(stks->a);
	stks->a = ft_stack_push(stks->a, elem);
}

// reverse rotate b
void	rrb(t_two_stks *stks)
{
	void	*elem;

	if (ft_stack_len(stks->b) < 1)
		return ;
	elem = ft_stack_pop_back(stks->b);
	stks->b = ft_stack_push(stks->b, elem);
}

// reverse rotate a and b
void	rrr(t_two_stks *stks)
{
	rra(stks);
	rrb(stks);
}
