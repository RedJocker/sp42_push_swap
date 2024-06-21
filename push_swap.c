/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:44:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/20 22:13:47 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_string.h"
#include "psargs.h"
#include "ft_stdio.h"

int	main(int argc, char *argv[])
{
	

	t_psargs	psargs;
	int			is_parseok;
	
	if (argc < 2)
		return (1);
	is_parseok = psargs_init(&psargs, argv + 1);
	if (is_parseok)
		(void) psargs;
	else
		ft_puterrl("Error");
	psargs_clean(&psargs);
	return (!is_parseok);
}
