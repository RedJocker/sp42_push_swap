/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:46:38 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 19:55:06 by maurodri         ###   ########.fr       */
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
