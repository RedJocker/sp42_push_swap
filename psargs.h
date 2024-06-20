/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psargs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:03:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/20 02:50:06 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSARGS_H
# define PSARGS_H

typedef struct s_psargs
{
	int	*iarr;
	int	len;
}	t_psargs;

int		psargs_init(t_psargs *out_psargs, char *in_arg);
void	psargs_clean(t_psargs *out_psargs);

#endif
