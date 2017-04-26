/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_lum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 21:41:10 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 21:41:12 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void			ft_verif_lum(t_e *e)
{
	e->vobject.name = 0;
	e->vobject.type = 0;
	e->vobject.typel = 0;
	e->vobject.color_rgb = 0;
	e->vobject.scale_xyz = 0;
	e->vobject.translate_xyz = 0;
	e->vobject.rotation_xyz = 0;
	e->vobject.normal_xyz = 0;
	e->vobject.x_min = 0;
	e->vobject.x_max = 0;
	e->vobject.y_min = 0;
	e->vobject.y_max = 0;
	e->vobject.z_min = 0;
	e->vobject.z_max = 0;
}

static void			ft_verif_nbr_lum(t_e *e, t_obj *tmp)
{
	if (e->vobject.name != 1)
		ft_puterror(e, "Wrong Info Light - name");
	if (e->vobject.type != 1)
		ft_puterror(e, "Wrong Info Light - type");
	if (e->vobject.typel != 1)
		ft_puterror(e, "Wrong Info Light - typel");
	if (e->vobject.color_rgb != 1)
		ft_puterror(e, "Wrong Info Light - color_rgb");
	if (e->vobject.scale_xyz != 1)
		ft_puterror(e, "Wrong Info Light - scale_xyz");
	if (e->vobject.translate_xyz != 1)
		ft_puterror(e, "Wrong Info Light - translate_xyz");
	if (e->vobject.rotation_xyz != 1)
		ft_puterror(e, "Wrong Info Light - rotation_xyz");
	if (tmp->typel != 1 && e->vobject.normal_xyz == 1)
	{
		tmp->normal.x = -1;
		tmp->normal.y = 0;
		tmp->normal.z = 0;
		tmp->normal.w = 1;
	}
	if (tmp->typel == 1 && e->vobject.normal_xyz != 1)
		ft_puterror(e, "Wrong Info Light - normal_xyz");
	ft_verif_limit_exist_lum(e, tmp);
}

static void			ft_free_lum(t_e *e)
{
	int				j;

	j = 0;
	if (e->split)
	{
		while (e->split[j] != NULL)
		{
			free(e->split[j]);
			j++;
		}
		free(e->split);
		e->split = NULL;
	}
}

t_obj				ft_parsing_lum(t_e *e, int i)
{
	t_obj			tmp;

	e->id_l++;
	tmp.refr_index = 0.1;
	i++;
	ft_verif_lum(e);
	while (i < e->nbr_line && i != -1)
	{
		e->line = i;
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->save_i = i;
			e->split = ft_strsplit(e->file[i], '\t');
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) == 0)
				ft_fill_info_lum(&tmp, e);
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) != 0)
				i = -2;
		}
		ft_free_lum(e);
		i++;
	}
	ft_verif_nbr_lum(e, &tmp);
	return (tmp);
}
