/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psargs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:02:28 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/19 22:24:52 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memlib.h"
#include "psargs.h"

int	psargs_init(t_psargs *out_psargs, char *in_arg)
{
	char		**sarr;
	int			is_ok;

	sarr = ft_split(in_arg, ' ');
	if (!sarr)
		return (0);
	out_psargs->len = 0;
	while (sarr[out_psargs->len])
		out_psargs->len++;
	out_psargs->iarr = ft_calloc(out_psargs->len, sizeof(int));
	if (!out_psargs->iarr)
		return (0);
	out_psargs->len = 0;
	is_ok = 1;
	while (sarr[out_psargs->len] != NULL)
	{
		if (is_ok)
			out_psargs->iarr[out_psargs->len] = (
				ft_atoi_strict(&is_ok, sarr[out_psargs->len]));
		free(sarr[out_psargs->len]);
		out_psargs->len++;
	}
	free(sarr);
	return (is_ok);
}

void	psargs_clean(t_psargs *out_psargs)
{
	if (out_psargs->iarr != NULL)
		free(out_psargs->iarr);
}
