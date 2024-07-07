/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:50:55 by maurodri          #+#    #+#             */
/*   Updated: 2024/07/06 23:47:56 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// now it goes!!!
#include "collection/ft_stack.h"
#include "ft_stdio.h"
#include "ft_util.h"
#include "two_stks.h"
#include "stat3.h"
#include <limits.h>


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
  	return (*item >= limit[0] && *item <= limit[1]);
}

void	sort3_return_a_sort3(t_two_stks *stks, t_stat3 *stat)
{
	int	*item[2];
	
	item[0] = ft_stack_peek(stks->b);
	item[1] = ft_stack_peek_last(stks->b);
	if (*item[0] == stat->max)
	{
	  	rb(stks);
		sb(stks);
		rrb(stks);
	}
	else if (*item[0] == stat->min)
	{
		rb(stks);
	  	if (*item[1] == stat->max)
			sb(stks);
	}
	else
	{
		if (*item[1] == stat->max)
			rrb(stks);
		else
			sb(stks);
	}
}

void	sort3_return_a_sortlt4(t_two_stks *stks)
{
	t_stat3	stat;
	int		bound[2];
	
	bound[0] = INT_MIN;
	bound[1] = INT_MAX;
	stat3_init(&stat);
	stat3_compute(&stat, stks->b, bound);
	if (stat.is_revsorted)
		return ;
	else if (stat.len == 2)
	 	sb(stks);
	else if (stat.len == 3)
		sort3_return_a_sort3(stks, &stat);
}

void sort3_return_a(t_two_stks *stks)
{
	int	*current;
	int	*bottom;

	ft_puterrl("returnA");
	current = ft_stack_peek(stks->b);
	while (ft_stack_len(stks->b) > 3)
	{
		bottom = ft_stack_peek_last(stks->b);
		(void) bottom;
		//if (ft_int_lt(current, bottom) && ft_stack_len(stks->b) > 3)
		//	rb(stks);
		//else
			pa(stks);
		current = ft_stack_peek(stks->b);
	}
	//	sort3_return_a_sortlt4(stks);
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

void sort3_fst_pos_lower(t_two_stks *stks, t_stat3 *stat, int *item)
{
	int	*next;

	
	ft_puterrl("lower");
	next = ft_stack_peek_next(stks->a);
	if (next && item_lower(next, stat) && ft_int_lt(next, item))
	{
		/* sa(stks); */
		/* pb(stks); */
		pb(stks);
		/* if (next == stat->last) */
		/* 	stat->last = item; */
	}
	else
		pb(stks);
}

void sort3_fst_pos_higher(t_two_stks *stks, t_stat3 *stat, int *item)
{
	int	*next;
	int *item_a;
	
	(void) item;
	ft_puterrl("higher");
	pb(stks);
	next = ft_stack_peek_next(stks->b);
	item_a = ft_stack_peek(stks->a);
	if (next && !item_higher(next, stat))
	{
		if (item_middle(item_a, stat))
			rr(stks);
		else
			rb(stks);
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
			sort3_fst_pos_lower(stks, stat, item);
		else if (item_middle(item, stat))
		{
		  	// maybe count non middle and break when only middle 
		  	ft_puterrl("middle");
			ra(stks);
		}	
		else if (item_higher(item, stat))
			sort3_fst_pos_higher(stks, stat, item);
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
			ra(stks);
		else
			break ;
	}
}

void	sort3_e3(t_two_stks *stks, t_stat3 *stat)
{
	int	*item[2];
	
	item[0] = ft_stack_peek(stks->a);
	item[1] = ft_stack_peek_next(stks->a);
	if (*item[0] == stat->min)
	{
	  	pb(stks);
		sa(stks);
		pa(stks);
	}
	else if (*item[0] == stat->max)
	{
		sa(stks);
		pb(stks);
		sa(stks);
		pa(stks);
	  	if (*item[1] != stat->min)
			sa(stks);
	}
	else
	{
		if (*item[1] == stat->min)
			sa(stks);
		else
		{
			pb(stks);
			sa(stks);
			pa(stks);
			sa(stks);
		}
	}
}

void	sort3_e4(t_two_stks *stks)
{
	int	*item[3];
	int	i;

	i = 0;
	while (i < 4)
	{
		item[0] = ft_stack_peek(stks->a);
		item[1] = ft_stack_peek_next(stks->a);
		if (item[1] && *item[0] > *item[1])
		{
			sa(stks);
			continue ;
		}
		else
		{
			pb(stks);
			item[1] = ft_stack_peek_next(stks->b);
			item[2] = ft_stack_peek_last(stks->b);
			if (item[2] && *item[0] < *item[2])
				rb(stks);
			else if (item[1] && *item[0] < *item[1])
				sb(stks);
			}
			i++;
		}
	i = 0;
	while (i < 4)
	{
		item[0] = ft_stack_peek(stks->b);
		item[1] = ft_stack_peek_next(stks->b);
		if (item[1] && *item[0] < *item[1])
		{
			sb(stks);
			continue ;
		}
		else
		{
			pa(stks);
		}
		i++;
	}
}  


void	sort3_le4(t_two_stks *stks, t_stat3 *stat)
{
	if (stat->len == 2)
		sa(stks);
	else if (stat->len == 3)
		sort3_e3(stks, stat);
	else
		sort3_e4(stks);
}

void	sort3_sort(t_two_stks *stks, int bound[2])
{
	t_stat3 stat;
	int		partition[2];

	stat3_init(&stat);
	stat3_compute(&stat, stks->a, bound);
	stat3_print(&stat);
	two_stks_print(stks);
	if (stat.is_sorted)
		return ;
	if (stat.len <= 4)
	  return (sort3_le4(stks, &stat));
	sort3_fst_pos(stks, &stat);
	two_stks_print(stks);
	sort3_snd_pos(stks, &stat);
	two_stks_print(stks);
	sort3_return_a(stks);
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
