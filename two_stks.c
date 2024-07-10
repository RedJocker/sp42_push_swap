/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:46:38 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/10 15:01:37 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_memlib.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "two_stks.h"

t_two_stks	*two_stks_new(void)
{
	t_two_stks	*stks;

	stks = malloc(sizeof(t_two_stks));
	if (!stks)
		return (NULL);
	stks->a = ft_stack_new((t_consumer) ft_nop);
	if (!stks->a)
		return (ft_free_retnull(stks));
	stks->b = ft_stack_new((t_consumer) ft_nop);
	if (!stks->b)
	{
		free(stks->a);
		return (ft_free_retnull(stks));
	}
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
	ft_puterr("A::");
	ft_stack_printerr(stks->a, (t_consumer) ft_int_printerr);
	ft_puterr("B::");
	ft_stack_printerr(stks->b, (t_consumer) ft_int_printerr);
}

void	two_stks_init(t_two_stks *stks, t_psargs *psargs)
{
	int	i;

	i = psargs->len;
	while (--i >= 0)
		ft_stack_push(stks->a, psargs->iarr + i);
}

void	two_stks_sort(t_two_stks *stks, t_consumer sort_impl)
{
	sort_impl(stks);
}

void	stack_swap(t_stack stk)
{
	void	*elem0;
	void	*elem1;

	elem0 = ft_stack_pop(stk);
	elem1 = ft_stack_pop(stk);
	stk = ft_stack_push(stk, elem0);
	stk = ft_stack_push(stk, elem1);
}

// swap a
void	sa(t_two_stks *stks)
{
	stack_swap(stks->a);
	ft_putendl("sa");
	ft_puterrl("sa");
}

// swap b
void	sb(t_two_stks *stks)
{
	stack_swap(stks->b);
	ft_putendl("sb");
	ft_puterrl("sb");
}

// swap a and b
void	ss(t_two_stks *stks)
{
	stack_swap(stks->a);
	stack_swap(stks->b);
	ft_putendl("ss");
	ft_puterrl("ss");
}

// push a
void	pa(t_two_stks *stks)
{
	void	*elem;

	elem = ft_stack_pop(stks->b);
	stks->a = ft_stack_push(stks->a, elem);
	ft_putendl("pa");
	ft_puterrl("pa");
}

// push b
void	pb(t_two_stks *stks)
{
	void	*elem;

	elem = ft_stack_pop(stks->a);
	stks->b = ft_stack_push(stks->b, elem);
	ft_putendl("pb");
	ft_puterrl("pb");
}

void	stack_rotate(t_stack stk)
{
	void	*elem;

	elem = ft_stack_pop(stk);
	stk = ft_stack_push_back(stk, elem);
}

// rotate a
void	ra(t_two_stks *stks)
{
	stack_rotate(stks->a);
	ft_putendl("ra");
	ft_puterrl("ra");
}

// rotate b
void	rb(t_two_stks *stks)
{
	stack_rotate(stks->b);
	ft_putendl("rb");
	ft_puterrl("rb");
}

// rotate a and b
void	rr(t_two_stks *stks)
{
	stack_rotate(stks->a);
	stack_rotate(stks->b);
	ft_putendl("rr");
	ft_puterrl("rr");
}

void	stack_rev_rotate(t_stack stk)
{
	void	*elem;

	elem = ft_stack_pop_back(stk);
	stk = ft_stack_push(stk, elem);
}

// reverse rotate a
void	rra(t_two_stks *stks)
{
	stack_rev_rotate(stks->a);
	ft_putendl("rra");
	ft_puterrl("rra");
}

// reverse rotate b
void	rrb(t_two_stks *stks)
{
	stack_rev_rotate(stks->b);
	ft_putendl("rrb");
	ft_puterrl("rrb");
}

// reverse rotate a and b
void	rrr(t_two_stks *stks)
{
	stack_rev_rotate(stks->a);
	stack_rev_rotate(stks->b);
	ft_putendl("rrr");
	ft_puterrl("rrr");
}
