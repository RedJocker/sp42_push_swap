/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:57:22 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/20 23:55:01 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two_stks.h"
#include <assert.h>
#include <limits.h>
#include "collection/ft_stack.h"
#include "collection/ft_arraylist.h"
#include "ft_util.h"
#include "ft_stdio.h"
#include "psargs.h"
#include "push_swap.h"

void test_sa()
{
	t_two_stks *stks;
	t_stack 	expected;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_sa::");
	stks = two_stks_new();
	expected = ft_stack_new((t_consumer) ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->a = ft_stack_push(stks->a, arr + 0);
	stks->a = ft_stack_push(stks->a, arr + 1);
	ft_stack_print(stks->a, (t_consumer) ft_int_print);
	expected = ft_stack_push(expected, arr + 1);
	expected = ft_stack_push(expected, arr + 0);
	sa(stks);
	ft_putendl("sa()");
	ft_stack_print(stks->a, (t_consumer) ft_int_print);
	assert(ft_arraylist_equal(
						stks->a,
						expected, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop(expected);
	ft_stack_pop(expected);
	stks->a = ft_stack_push(stks->a, arr + 2);
	ft_stack_print(stks->a, (t_consumer)ft_int_print);
	sa(stks);
	ft_putendl("sa()");
	ft_stack_print(stks->a, (t_consumer) ft_int_print);
	expected = ft_stack_push(expected, arr + 1);
	expected = ft_stack_push(expected, arr + 2);
	expected = ft_stack_push(expected, arr + 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected);
	two_stks_destroy(stks);
}

void test_sb()
{
	t_two_stks *stks;
	t_stack 	expected;
	int         arr[10];
	int			i;
	
	ft_putendl("\n::test_sb::");
	stks = two_stks_new();
	expected = ft_stack_new((t_consumer) ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->b = ft_stack_push(stks->b, arr + 0);
	stks->b = ft_stack_push(stks->b, arr + 1);
	ft_stack_print(stks->b, (t_consumer) ft_int_print);
	expected = ft_stack_push(expected, arr + 1);
	expected = ft_stack_push(expected, arr + 0);
	sb(stks);
	ft_putendl("sb()");
	ft_stack_print(stks->b, (t_consumer) ft_int_print);
	assert(ft_arraylist_equal(
						stks->b,
						expected, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop(expected);
	ft_stack_pop(expected);
	stks->b = ft_stack_push(stks->b, arr + 2);
	ft_stack_print(stks->b, (t_consumer) ft_int_print);
	sb(stks);
	ft_putendl("sb()");
	ft_stack_print(stks->b, (t_consumer) ft_int_print);
	expected = ft_stack_push(expected, arr + 1);
	expected = ft_stack_push(expected, arr + 2);
	expected = ft_stack_push(expected, arr + 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected);
	two_stks_destroy(stks);
}

void test_ss()
{
	t_two_stks *stks;
	t_stack 	expected_a;
	t_stack 	expected_b;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_ss::");
	stks = two_stks_new();
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->a = ft_stack_push(stks->a, arr + 0);
	stks->a = ft_stack_push(stks->a, arr + 1);
	
	expected_a = ft_stack_push(expected_a, arr + 1);
	expected_a = ft_stack_push(expected_a, arr + 0);
	stks->b = ft_stack_push(stks->b, arr + 4);
	stks->b = ft_stack_push(stks->b, arr + 5);
	two_stks_print(stks);
	expected_b = ft_stack_push(expected_b, arr + 5);
	expected_b = ft_stack_push(expected_b, arr + 4);
	ss(stks);
	ft_putendl("ss()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop(expected_a);
	ft_stack_pop(expected_a);
	ft_stack_pop(expected_b);
	ft_stack_pop(expected_b);
	stks->a = ft_stack_push(stks->a, arr + 2);
	stks->b = ft_stack_push(stks->b, arr + 6);
	two_stks_print(stks);
	ss(stks);
	ft_putendl("ss()");
	two_stks_print(stks);
	expected_a = ft_stack_push(expected_a, arr + 1);
	expected_a = ft_stack_push(expected_a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 0);
	expected_b = ft_stack_push(expected_b, arr + 5);
	expected_b = ft_stack_push(expected_b, arr + 6);
	expected_b = ft_stack_push(expected_b, arr + 4);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_a);
	ft_stack_destroy(expected_b);
	two_stks_destroy(stks);
}

void test_pa()
{
	t_two_stks *stks;
	t_stack 	expected_a;
	t_stack 	expected_b;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_pa::");
	stks = two_stks_new();
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->b = ft_stack_push(stks->b, arr + 0);
	stks->b = ft_stack_push(stks->b, arr + 1);
	stks->b = ft_stack_push(stks->b, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 2);
	expected_b = ft_stack_push(expected_b, arr + 0);
	expected_b = ft_stack_push(expected_b, arr + 1);
	two_stks_print(stks);
	pa(stks);
	ft_putendl("pa()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop(expected_b);
	expected_a = ft_stack_push(expected_a, arr + 1);
	pa(stks);
	ft_putendl("pa()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop(expected_b);
	expected_a = ft_stack_push(expected_a, arr + 0);
	pa(stks);
	ft_putendl("pa()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	pa(stks);
	ft_putendl("pa()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_a);
	ft_stack_destroy(expected_b);
	two_stks_destroy(stks);
}


void test_pb()
{
	t_two_stks *stks;
	t_stack 	expected_b;
	t_stack 	expected_a;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_pb::");
	stks = two_stks_new();
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->a = ft_stack_push(stks->a, arr + 0);
	stks->a = ft_stack_push(stks->a, arr + 1);
	stks->a = ft_stack_push(stks->a, arr + 2);
	expected_b = ft_stack_push(expected_b, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 0);
	expected_a = ft_stack_push(expected_a, arr + 1);
	two_stks_print(stks);
	pb(stks);
	ft_putendl("pb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop(expected_a);
	expected_b = ft_stack_push(expected_b, arr + 1);
	pb(stks);
	ft_putendl("pb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop(expected_a);
	expected_b = ft_stack_push(expected_b, arr + 0);
	pb(stks);
	ft_putendl("pb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	pb(stks);
	ft_putendl("pb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_b);
	ft_stack_destroy(expected_a);
	two_stks_destroy(stks);
}

void test_ra()
{
	t_two_stks *stks;
	t_stack 	expected_b;
	t_stack 	expected_a;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_ra::");
	stks = two_stks_new();
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->a = ft_stack_push(stks->a, arr + 0);
	stks->a = ft_stack_push(stks->a, arr + 1);
	stks->a = ft_stack_push(stks->a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 0);
	expected_a = ft_stack_push(expected_a, arr + 1);
	two_stks_print(stks);
	ra(stks);
	ft_putendl("ra()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop(expected_a);
	ft_stack_push_back(expected_a, arr + 1);
	ra(stks);
	ft_putendl("ra()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop(expected_a);
	ft_stack_push_back(expected_a, arr + 0);
	ra(stks);
	ft_putendl("ra()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_b);
	ft_stack_destroy(expected_a);
	two_stks_destroy(stks);
}

void test_rb()
{
	t_two_stks *stks;
	t_stack 	expected_a;
	t_stack 	expected_b;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_rb::");
	stks = two_stks_new();
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->b = ft_stack_push(stks->b, arr + 0);
	stks->b = ft_stack_push(stks->b, arr + 1);
	stks->b = ft_stack_push(stks->b, arr + 2);
	expected_b = ft_stack_push(expected_b, arr + 2);
	expected_b = ft_stack_push(expected_b, arr + 0);
	expected_b = ft_stack_push(expected_b, arr + 1);
	two_stks_print(stks);
	rb(stks);
	ft_putendl("rb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop(expected_b);
	ft_stack_push_back(expected_b, arr + 1);
	rb(stks);
	ft_putendl("rb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop(expected_b);
	ft_stack_push_back(expected_b, arr + 0);
	rb(stks);
	ft_putendl("rb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_a);
	ft_stack_destroy(expected_b);
	two_stks_destroy(stks);
}

void test_rr()
{
	t_two_stks *stks;
	t_stack 	expected_a;
	t_stack 	expected_b;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_rr::");
	stks = two_stks_new();
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->a = ft_stack_push(stks->a, arr + 0);
	stks->a = ft_stack_push(stks->a, arr + 1);
	stks->a = ft_stack_push(stks->a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 0);
	expected_a = ft_stack_push(expected_a, arr + 1);
	stks->b = ft_stack_push(stks->b, arr + 5);
	stks->b = ft_stack_push(stks->b, arr + 6);
	stks->b = ft_stack_push(stks->b, arr + 7);
	expected_b = ft_stack_push(expected_b, arr + 7);
	expected_b = ft_stack_push(expected_b, arr + 5);
	expected_b = ft_stack_push(expected_b, arr + 6);
	two_stks_print(stks);
	rr(stks);
	ft_putendl("rr()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop(expected_a);
	ft_stack_push_back(expected_a, arr + 1);
	ft_stack_pop(expected_b);
	ft_stack_push_back(expected_b, arr + 6);
	rr(stks);
	ft_putendl("rr()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop(expected_a);
	ft_stack_push_back(expected_a, arr + 0);
	ft_stack_pop(expected_b);
	ft_stack_push_back(expected_b, arr + 5);
	rr(stks);
	ft_putendl("rr()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_a);
	ft_stack_destroy(expected_b);
	two_stks_destroy(stks);
}

void test_rra()
{
	t_two_stks *stks;
	t_stack 	expected_b;
	t_stack 	expected_a;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_rra::");
	stks = two_stks_new();
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->a = ft_stack_push(stks->a, arr + 0);
	stks->a = ft_stack_push(stks->a, arr + 1);
	stks->a = ft_stack_push(stks->a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 1);
	expected_a = ft_stack_push(expected_a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 0);
	two_stks_print(stks);
	rra(stks);
	ft_putendl("rra()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop_back(expected_a);
	ft_stack_push(expected_a, arr + 1);
	rra(stks);
	ft_putendl("rra()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop_back(expected_a);
	ft_stack_push(expected_a, arr + 2);
	rra(stks);
	ft_putendl("rra()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_b);
	ft_stack_destroy(expected_a);
	two_stks_destroy(stks);
}

void test_rrb()
{
	t_two_stks *stks;
	t_stack 	expected_a;
	t_stack 	expected_b;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_rrb::");
	stks = two_stks_new();
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->b = ft_stack_push(stks->b, arr + 0);
	stks->b = ft_stack_push(stks->b, arr + 1);
	stks->b = ft_stack_push(stks->b, arr + 2);
	expected_b = ft_stack_push(expected_b, arr + 1);
	expected_b = ft_stack_push(expected_b, arr + 2);
	expected_b = ft_stack_push(expected_b, arr + 0);
	two_stks_print(stks);
	rrb(stks);
	ft_putendl("rrb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop_back(expected_b);
	ft_stack_push(expected_b, arr + 1);
	rrb(stks);
	ft_putendl("rrb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop_back(expected_b);
	ft_stack_push(expected_b, arr + 2);
	rrb(stks);
	ft_putendl("rrb()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_a);
	ft_stack_destroy(expected_b);
	two_stks_destroy(stks);
}

void test_rrr()
{
	t_two_stks *stks;
	t_stack 	expected_a;
	t_stack 	expected_b;
	int         arr[10];
	int			i;

	ft_putendl("\n::test_rrr::");
	stks = two_stks_new();
	expected_a = ft_stack_new((void (*)(void*))ft_nop);
	expected_b = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->a = ft_stack_push(stks->a, arr + 0);
	stks->a = ft_stack_push(stks->a, arr + 1);
	stks->a = ft_stack_push(stks->a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 1);
	expected_a = ft_stack_push(expected_a, arr + 2);
	expected_a = ft_stack_push(expected_a, arr + 0);
	stks->b = ft_stack_push(stks->b, arr + 5);
	stks->b = ft_stack_push(stks->b, arr + 6);
	stks->b = ft_stack_push(stks->b, arr + 7);
	expected_b = ft_stack_push(expected_b, arr + 6);
	expected_b = ft_stack_push(expected_b, arr + 7);
	expected_b = ft_stack_push(expected_b, arr + 5);
	two_stks_print(stks);
	rrr(stks);
	ft_putendl("rrr()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun)ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun)ft_int_equal) != 0);
	ft_stack_pop_back(expected_a);
	ft_stack_push(expected_a, arr + 1);
	ft_stack_pop_back(expected_b);
	ft_stack_push(expected_b, arr + 6);
	rrr(stks);
	ft_putendl("rrr()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_pop_back(expected_a);
	ft_stack_push(expected_a, arr + 2);
	ft_stack_pop_back(expected_b);
	ft_stack_push(expected_b, arr + 7);
	rrr(stks);
	ft_putendl("rrr()");
	two_stks_print(stks);
	assert(ft_arraylist_equal(
						stks->a,
						expected_a, 
					(t_intbifun) ft_int_equal) != 0);
	assert(ft_arraylist_equal(
						stks->b,
						expected_b, 
					(t_intbifun) ft_int_equal) != 0);
	ft_stack_destroy(expected_a);
	ft_stack_destroy(expected_b);
	two_stks_destroy(stks);
}

void	test_psargs_0(void)
{
	char		*str[] = {0};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_0::");
	ft_putstr("str: ");
	ft_putendl("{}");
	is_parseok = psargs_init(&psargs, str, 0);
	assert(is_parseok != 0);
	assert(psargs.len == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_1(void)
{
	char		*str[] = { "1", "2", "3"};
	t_psargs	psargs = {0};
	int			is_parseok;

	ft_putendl("\n::test_psargs_1::");
	ft_putstr("str: ");
	ft_putendl("{1, 2, 3}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok != 0);
	assert(psargs.len == 3);
	assert(psargs.iarr[0] == 1);
	assert(psargs.iarr[1] == 2);
	assert(psargs.iarr[2] == 3);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_2(void)
{
	char		*str[] = {"300", "20", "1", "-5", "-60", "-800"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_2::");
	ft_putstr("str: ");
	ft_putendl("{300 20 1 -5 -60 -800}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok != 0);
	assert(psargs.len == 6);
	assert(psargs.iarr[0] == 300);
	assert(psargs.iarr[1] == 20);
	assert(psargs.iarr[2] == 1);
	assert(psargs.iarr[3] == -5);
	assert(psargs.iarr[4] == -60);
	assert(psargs.iarr[5] == -800);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_3(void)
{
	char		*str[] = {"300", "20", "1", "abc", "-60", "-800"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_3::");
	ft_putstr("str: ");
	ft_putendl("{300 20 1 abc -60 -800}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_4(void)
{
	char		*str[] = {"2147483647", "-2147483648"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_4::");
	ft_putstr("str: ");
	ft_putendl("{2147483647 -2147483648}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok != 0);
	assert(psargs.len == 2);
	assert(psargs.iarr[0] == INT_MAX);
	assert(psargs.iarr[1] == INT_MIN);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_5(void)
{
	char		*str[] = {"2147483648"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_5::");
	ft_putstr("str: ");
	ft_putendl("{2147483648}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}


void	test_psargs_6(void)
{
	char		*str[] = {"-2147483649"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_6::");
	ft_putstr("str: ");
	ft_putendl("{-2147483649}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}


void	test_psargs_7(void)
{
	char		*str[] = {"10a"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_7::");
	ft_putstr("str: ");
	ft_putendl("{10a}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_8(void)
{
	char		*str[] = {"2a3"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_8::");
	ft_putstr("str: ");
	ft_putendl("{2a3}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}


void	test_psargs_9(void)
{
	char		*str[] = {"1", "2", "3", "2a2"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_9::");
	ft_putstr("str: ");
	ft_putendl("{1 2 3 2a2}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_10(void)
{
	char		*str[] = {"1", "1"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_10::");
	ft_putstr("str: ");
	ft_putendl("{1 1}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_11(void)
{
	char		*str[] = {"-10", "-10"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_11::");
	ft_putstr("str: ");
	ft_putendl("{-10 -10}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}


void	test_psargs_12(void)
{
	char *str[] = {"1","2","1"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_12::");
	ft_putstr("str: ");
	ft_putendl("{1 2 1}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}


void	test_psargs_13(void)
{
	char *str[] = {
		"-10",
		"50",
		"900",
		"22",
		"51",
		"222",
		"30",
		"40",
		"0",
		"999",
		"1000",
		"5001",
		"2",
		"3",
		"7",
		"10",
		"-10"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_13::");
	ft_putstr("str: ");
	ft_putendl("{-10 50 900 22 51 222 30 40 0 999 1000 5001 2 3 7 10 -10}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 0);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void	test_psargs_14(void)
{
	char *str[] = {
		"-10",
		"50",
		"900",
		"22",
		"51",
		"222",
		"30",
		"40",
		"0",
		"999",
		"1000",
		"5001",
		"2",
		"3",
		"7",
		"10",
		"-1"};
	t_psargs	psargs;
	int			is_parseok;

	ft_putendl("\n::test_psargs_14::");
	ft_putstr("str: ");
	ft_putendl("{-10 50 900 22 51 222 30 40 0 999 1000 5001 2 3 7 10 -1}");
	is_parseok = psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	assert(is_parseok == 1);
	assert(psargs.len == 17);
	psargs_clean(&psargs);
	ft_putendl("OK");
}

void test_empty_argv_fails()
{
	char *argv[] = {"./push_swap"};
	int argc = sizeof(argv) / sizeof(char *);
	int ret;

	ft_putendl("\n::test_empty_argv_fails::");
	ret = testable_main(argc, argv);
	assert(ret != 0);
}

void test_invalid_argv_fails()
{
	char *argv[] = {"./push_swap", "abc"};
	int argc = sizeof(argv) / sizeof(char *);
	int ret;

	ft_putendl("\n::test_empty_argv_fails::");
	ret = testable_main(argc, argv);
	assert(ret != 0);
}

void test_two_stck_init()
{
	/* char *argv[] = {"./push_swap", "abc"}; */
	/* int argc = sizeof(argv) / sizeof(char *); */
	/* int ret; */
	char *str[] = {
		"-10",
		"50",
		"900",
		"22",
		"51",
		"222",
		"30",
		"40",
		"0",
		"999",
		"1000",
		"5001",
		"2",
		"3",
		"7",
		"10",
		"-1"};
	int	ints[] = {
		-10,
		50,
		900,
		22,
		51,
		222,
		30,
		40,
		0,
		999,
		1000,
		5001,
		2,
		3,
		7,
		10,
		-1};
	t_psargs	psargs;
	t_two_stks	*stks;
	int			len;
	int			i;
	
	ft_putendl("\n:: test_two_stck_init::");
	len = (int) sizeof(str) / sizeof(char *);
	psargs_init(&psargs, str, sizeof(str) / sizeof(char *));
	stks = two_stks_new();
	two_stks_init(stks, &psargs);
	two_stks_print(stks);
	assert(ft_stack_len(stks->a) == (size_t) len);
	i = -1;
	while (++i < len)
		assert(*((int *) ft_stack_pop(stks->a)) == ints[i]);
	psargs_clean(&psargs);
	two_stks_destroy(stks);
}

int main(void)
{
	ft_putendl("\n==S T A R T==");
	test_sa();
	test_sb();
	test_ss();
	test_pa();
	test_pb();
	test_ra();
	test_rb();
	test_rr();
	test_rra();
	test_rrb();
	test_rrr();
	test_psargs_0();
	test_psargs_1();
	test_psargs_2();
	test_psargs_3();
	test_psargs_4();
	test_psargs_5();
	test_psargs_6();
	test_psargs_7();
	test_psargs_8();
	test_psargs_9();
	test_psargs_10();
	test_psargs_11();
	test_psargs_12();
	test_psargs_13();
	test_psargs_14();
	test_empty_argv_fails();
	test_invalid_argv_fails();
	test_two_stck_init();
	ft_putendl("\n==E N D==\n");
}
