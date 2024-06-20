/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:44:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/20 14:45:44 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_string.h"
#include "psargs.h"

int	main(void)
{
	char		str[100];
	t_psargs	psargs;
	int			is_parseok;

	ft_strlcpy(str, "10 20 30", 100);
	is_parseok = psargs_init(&psargs, str);
	if (is_parseok)
		(void) psargs;
	psargs_clean(&psargs);
	return (0);
}
