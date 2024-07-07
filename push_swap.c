/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:44:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/06 18:47:35 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "psargs.h"
#include "ft_stdio.h"
#include "two_stks.h"
#include "ft_util.h"
#include "limits.h"
#include "sort3.h"

void	two_stcks_sort_naive(t_two_stks *stks);
void	two_stcks_sort_two(t_two_stks *stks);

static void	anonymous_fun(t_two_stks *stks)
{
	int	bound[2];

	bound[0] = INT_MIN;
	bound[1] = INT_MAX;
	ft_puterrl("START");
	two_stks_print(stks);
	sort3_sort(stks, bound);
	two_stks_print(stks);
	ft_puterrl("END");
}

void	two_stcks_sort(t_two_stks *stks, t_consumer sort_impl)
{
	sort_impl(stks);
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
		two_stks_sort(stks, (t_consumer) anonymous_fun);
	}
	else
		ft_puterrl("Error");
	two_stks_destroy(stks);
	psargs_clean(&psargs);
	return (!is_parseok);
}
