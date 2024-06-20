/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:44:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/19 20:09:49 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "psargs.h"
#include <assert.h>

int	main(void)
{
	char		*str = "10 20 30";
	t_psargs	psargs;
	int			is_parseok;

	is_parseok = psargs_init(&psargs, str);
	assert(is_parseok != 0);
	assert(psargs.len == 3);
	assert(psargs.iarr[0] == 10);
	assert(psargs.iarr[1] == 20);
	assert(psargs.iarr[2] == 30);
	printf("hey");
	psargs_clean(&psargs);
	return (0);
}
