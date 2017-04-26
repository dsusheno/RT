/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:02:02 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/04 16:23:01 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	imaginary_ray(t_ray ray, t_transform t)
{
	t_ray	new;

	new.origin = inver_origin(ray.origin, t);
	new.dir = inver_dir(ray.dir, t);
	return (new);
}

void	get_nearest_one_obj1(t_ray ray, t_obj obj, t_ray *img_ray, float *dist)
{
	if (obj.type == 2)
		*dist = plane_dist(obj, ray);
	if (obj.type == 3)
	{
		*img_ray = imaginary_ray(ray, obj.transform);
		*dist = cone_dist(*img_ray, obj);
	}
	if (obj.type == 4)
		*dist = triangle_dist(ray, *obj.faces);
	if (obj.type == 7)
		*dist = circle_dist(ray, obj);
	if (obj.type == 8)
	{
		*img_ray = imaginary_ray(ray, obj.transform);
		*dist = quadrics_dist(*img_ray, obj);
	}
}

float	get_nearest_one_obj(t_ray ray, t_obj obj, t_pret *poly, t_ray *img_ray)
{
	float	dist;

	if (obj.type == 0)
	{
		*img_ray = imaginary_ray(ray, obj.transform);
		dist = sphere_dist(*img_ray, obj);
	}
	if (obj.type == 1)
	{
		*img_ray = imaginary_ray(ray, obj.transform);
		dist = cylindre_dist(*img_ray, obj);
	}
	if (obj.type == 5 || obj.type == 6)
	{
		*poly = polygone_dist(ray, obj);
		dist = poly->dist;
	}
	get_nearest_one_obj1(ray, obj, img_ray, &dist);
	return (dist);
}

void	fill_no(t_no *no, t_obj obj, t_ray img_ray, t_pret poly)
{
	no->obj = obj;
	no->img_ray = img_ray;
	if (obj.type == 5 || obj.type == 6)
		no->poly_face = poly.no;
	else
		no->poly_face = NULL;
}

int		get_nearest_obj(t_ray ray, t_list *list, t_no *no)
{
	t_list	*tmp;
	float	dist[2];
	t_ray	img_ray;
	t_obj	obj;
	t_pret	poly;

	tmp = list;
	dist[0] = -1;
	dist[1] = -1;
	while (tmp)
	{
		obj = *(t_obj*)(tmp->content);
		dist[1] = get_nearest_one_obj(ray, obj, &poly, &img_ray);
		if (dist[1] > SHADOW_BIAS && ((dist[0] == -1) || (dist[1] < dist[0])))
		{
			dist[0] = dist[1];
			fill_no(no, obj, img_ray, poly);
		}
		tmp = tmp->next;
	}
	if (dist[0] <= 0)
		return (0);
	no->ip = set_inter_point(dist[0], ray);
	no->origin = ray;
	return (1);
}
