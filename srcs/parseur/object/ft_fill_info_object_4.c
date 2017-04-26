/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info_object_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:47:58 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 22:48:00 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void			ft_fill_info_object_20(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "quadrics") == 0 && e->split[1] != NULL
	&& e->split[2] != NULL && e->split[3] != NULL && e->split[4] != NULL
	&& e->split[5] != NULL && e->split[6] != NULL && e->split[7] != NULL &&
	e->split[8] != NULL && e->split[9] != NULL && e->split[10] != NULL)
	{
		e->vobject.quadrics++;
		obj->quadrics = (t_quadrics){ stof(e->split[1]), stof(e->split[2]),
			stof(e->split[3]), stof(e->split[4]), stof(e->split[5]),
			stof(e->split[6]), stof(e->split[7]), stof(e->split[8]),
			stof(e->split[9]), stof(e->split[10])};
	}
	else
		ft_puterror(e, ft_strjoin("Wrong Info Object line ",
			ft_itoa(e->save_i + 1)));
}

static void			ft_fill_info_object_19(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "y_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.y_max = 1;
		e->vobject.y_max++;
		obj->limit.y_max = stof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "z_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.z_min = 1;
		e->vobject.z_min++;
		obj->limit.z_min = stof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "z_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.z_max = 1;
		e->vobject.z_max++;
		obj->limit.z_max = stof(e->split[1]);
	}
	else
		ft_fill_info_object_20(obj, e);
}

void				ft_fill_info_object_18(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "x_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.x_min = 1;
		e->vobject.x_min++;
		obj->limit.x_min = stof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "x_max") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.x_max = 1;
		e->vobject.x_max++;
		obj->limit.x_max = stof(e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "y_min") == 0 && e->split[1] != NULL)
	{
		obj->limit.exist.y_min = 1;
		e->vobject.y_min++;
		obj->limit.y_min = stof(e->split[1]);
	}
	else
		ft_fill_info_object_19(obj, e);
}
