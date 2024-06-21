/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:44:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/21 00:15:23 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_string.h"
#include "psargs.h"
#include "ft_stdio.h"
#include "two_stks.h"
#include "ft_util.h"

void	two_stcks_sort(t_two_stks *stks, t_consumer sort_impl)
{
	sort_impl(stks);
}

void	two_stcks_sort_naive(t_two_stks *stks)
{
	(void) stks;
}

int	testable_main(int argc, char *argv[])
{
	t_psargs	psargs;
	int			is_parseok;
	t_two_stks	*stks;

	if (argc < 2)
		return (1);
	stks = two_stks_new();
	is_parseok = psargs_init(&psargs, argv + 1, argc - 1);
	if (is_parseok)
	{
		two_stks_init(stks, &psargs);
		two_stks_sort(stks, (t_consumer) two_stcks_sort_naive);
	}
	else
		ft_puterrl("Error");
	two_stks_destroy(stks);
	psargs_clean(&psargs);
	return (!is_parseok);
}
