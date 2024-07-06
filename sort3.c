/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:50:55 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/06 07:22:51 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// now it goes!!!
#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "two_stks.h"
#include "stat3.h"


int item_higher(int *item, t_stat3 *stat)
{
  	int limit[2];

  	if (item == NULL)
	  return (0);
	limit[0] = (int) (stat->min + (2 * stat->mean3)) + 1;
	limit[1] = (int) stat->max;
	return (*item >= limit[0] && *item <= limit[1]);
}

int item_middle(int *item, t_stat3 *stat)
{
 	int limit[2];

  	if (item == NULL)
	  return (0);
	limit[0] = (int) (stat->min + stat->mean3) + 1;
	limit[1] = (int) (stat->min + (2 * stat->mean3));
	return (*item >= limit[0] && *item <= limit[1]);
}	


int item_lower(int *item, t_stat3 *stat)
{
	int limit[2];

  	if (item == NULL)
	  return (0);
	limit[0] = (int) (stat->min);
	limit[1] = (int) (stat->min + stat->mean3);
  	return ((*item >= limit[0]
			&& *item <= limit[1])
				|| *item == limit[0]);
}

void sort3_returnA(t_two_stks *stks)
{
	int	*current;

	ft_puterrl("returnA");
	current = ft_stack_peek(stks->b);
	while (current)
	{
		pa(stks);
		current = ft_stack_peek(stks->b);
	}
}


void sort3_snd_pos(t_two_stks *stks, t_stat3 *stat)
{
	int *item;

	ft_puterrl("snd_pos");
	while (1)
	{
		item = ft_stack_peek(stks->a);	
		if (item_middle(item, stat))
			pb(stks);
		else
			break ;
	}
	while (1)
	{
		item = ft_stack_peek_last(stks->a);
		if (item_middle(item, stat))
		{
			rra(stks);
			pb(stks);
		}
		else
			break ;
	}
	while (1)
	{
		item = ft_stack_peek_last(stks->b);
		if (item_higher(item, stat))
		{
			rrb(stks);
		}
		else
			break ;
	}
}	


void sort3_fst_pos(t_two_stks *stks, t_stat3 *stat)
{
	int *item;
	ft_puterrl("fst_pos");
	while (1)
	{
		item = ft_stack_peek(stks->a);
		ft_puterr("item ");
		ft_int_printerr(item);
		ft_puterrl("");
		if (item_lower(item, stat))
		{
			ft_puterrl("lower");
			pb(stks);
		}
		else if (item_middle(item, stat))
		{
			ft_puterrl("middle");
			ra(stks);
		}	
		else if (item_higher(item, stat))
		{
			ft_puterrl("higher");
			pb(stks);
			rb(stks);
		}
		else
		{
			ft_puterrl("break1");
			break;
		}
		if (item == stat->last)
		{
			ft_puterrl("break last");
			break ;
		}
		
	}
}

void rotate_partition(t_two_stks *stks, int partition[2])
{
	int	*item;

	ft_puterrl("rotate_partition");
	while (1)
	{
		item = ft_stack_peek(stks->a);
		if (item && *item >= partition[0] && *item <= partition[1])
		{
			ra(stks);
		}
		else
			break ;
	}
}

void sort3_sort(t_two_stks *stks, int bound[2])
{
	t_stat3 stat;
	int		partition[2];

	stat3_init(&stat);
	stat3_compute(&stat, stks->a, bound);
	stat3_print(&stat);
	two_stks_print(stks);
	if (stat.is_sorted)
		return ;
	if (stat.len == 2)
	  return (sa(stks));
	sort3_fst_pos(stks, &stat);
	two_stks_print(stks);
	sort3_snd_pos(stks, &stat);
	two_stks_print(stks);
	sort3_returnA(stks);
	two_stks_print(stks);
	partition[0] = stat.min;
	partition[1] = stat.min + stat.mean3;
	sort3_sort(stks, partition);
	rotate_partition(stks, partition);
	partition[0] = partition[1] + 1;
	partition[1] = stat.min + (2 * stat.mean3);
	sort3_sort(stks, partition);
	rotate_partition(stks, partition);
	partition[0] = partition[1] + 1;
	partition[1] = stat.max;
	sort3_sort(stks, partition);
	rotate_partition(stks, partition);
}
