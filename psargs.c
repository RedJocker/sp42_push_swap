/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psargs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:02:28 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/20 22:36:49 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memlib.h"
#include "psargs.h"
#include "collection/ft_hashset.h"
#include "ft_util.h"

static size_t	int_hashfun(void *ele)
{
	int	*e;

	e = (int *) ele;
	return ((size_t) *(e));
}

static int	has_duplicates(t_psargs *psargs)
{
	t_hashset	hset;
	int			i;
	int			*curr;

	hset = ft_hashset_new(
			int_hashfun, (t_intbifun) ft_int_equal, (t_consumer) ft_nop);
	i = -1;
	while (++i < psargs->len)
	{
		curr = psargs->iarr + i;
		hset = ft_hashset_add(hset, curr);
		if (ft_hashset_len(hset) != (size_t) i + 1)
		{
			ft_hashset_destroy(hset);
			return (1);
		}
	}
	ft_hashset_destroy(hset);
	return (0);
}

int	psargs_init(t_psargs *out_psargs, char **in_args, int len)
{
	int			is_ok;

	if (!in_args)
		return (0);
	out_psargs->iarr = ft_calloc(len, sizeof(int));
	if (!out_psargs->iarr)
		return (0);
	out_psargs->len = 0;
	is_ok = 1;
	while (out_psargs->len < len)
	{
		if (is_ok)
		{
			out_psargs->iarr[out_psargs->len] = (
					ft_atoi_strict(&is_ok, in_args[out_psargs->len]));
		}
		out_psargs->len++;
	}
	is_ok = is_ok && (!has_duplicates(out_psargs));
	return (is_ok);
}

void	psargs_clean(t_psargs *out_psargs)
{
	if (out_psargs->iarr != NULL)
		free(out_psargs->iarr);
}
