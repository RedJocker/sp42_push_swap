/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:57:22 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/15 00:08:44 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two_stks.h"
#include <assert.h>
#include "collection/ft_stack.h"
#include "collection/ft_arraylist.h"
#include "ft_util.h"
#include "ft_stdio.h"

int	int_equal(int *a, int *b)
{
	return (*a == *b);
}

void	int_print(int *i)
{
	ft_putnbr_fd(*i, 1);
}

void test_sa()
{
	t_two_stks *stks;
	t_stack 	expected;
	int         arr[10];
	int			i;
	
	stks = t_two_stks_new();
	expected = ft_stack_new((void (*)(void*))ft_nop);
	i = -1;
	while (++i < 10)
		arr[i] = i;
	stks->a = ft_stack_push(stks->a, arr + 0);
	stks->a = ft_stack_push(stks->a, arr + 1);
	ft_stack_print(stks->a, (void (*)(void *))int_print);
	expected = ft_stack_push(expected, arr + 1);
	expected = ft_stack_push(expected, arr + 0);
	sa(stks);
	ft_putendl_fd("sa()", 1);
	ft_stack_print(stks->a, (void (*)(void *))int_print);
	assert(ft_arraylist_equal(
						stks->a,
						expected, 
					(int (*) (void *, void *))int_equal) != 0);
	ft_stack_pop(expected);
	ft_stack_pop(expected);
	stks->a = ft_stack_push(stks->a, arr + 2);
	ft_stack_print(stks->a, (void (*)(void *))int_print);
	sa(stks);
	ft_putendl_fd("sa()", 1);
	ft_stack_print(stks->a, (void (*)(void *)) int_print);
	expected = ft_stack_push(expected, arr + 1);
	expected = ft_stack_push(expected, arr + 2);
	expected = ft_stack_push(expected, arr + 0);
	assert(ft_arraylist_equal(
						stks->a,
						expected, 
					(int (*) (void *, void *))int_equal) != 0);
	ft_stack_destroy(expected);
	t_two_stks_destroy(stks);
}


int main(void)
{
	test_sa();
}
