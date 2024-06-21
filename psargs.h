/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psargs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:03:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/06/20 22:35:23 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSARGS_H
# define PSARGS_H

typedef struct s_psargs
{
	int	*iarr;
	int	len;
}	t_psargs;

int		psargs_init(t_psargs *out_psargs, char **in_args, int len);
void	psargs_clean(t_psargs *out_psargs);

#endif
