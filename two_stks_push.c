/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stks_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:48:21 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/11 20:34:05 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "two_stks.h"

void	pa(t_two_stks *stks)
{
	void	*elem;

	elem = ft_stack_pop(stks->b);
	stks->a = ft_stack_push(stks->a, elem);
	ft_putendl("pa");
}

void	pb(t_two_stks *stks)
{
	void	*elem;

	elem = ft_stack_pop(stks->a);
	stks->b = ft_stack_push(stks->b, elem);
	ft_putendl("pb");
}
