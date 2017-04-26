/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:15:29 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/04 16:16:03 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		diffuse_color(t_no no, t_obj lum, float k)
{
	t_color		color;

	color = color_fact(lum.color, no.obj.kd * (1 - no.t) * k);
	color = color_mult(color, no.color);
	return (color);
}

t_color		spec_color(t_obj obj, t_obj lum, float k)
{
	t_color		color;

	color = color_fact(lum.color, obj.ks * k);
	return (color);
}

t_color		cc_l(t_obj lum, t_no no, t_vec3d n, t_vec3d origin)
{
	t_vec3d	light;
	t_vec3d	halfway;
	t_vec3d	view;
	t_color	ret;

	ret = color_init();
	light = normalizevec(vector_sub(lum.transform.transl, no.ip));
	if (vector_dot(light, n) > 0.0)
	{
		view = normalizevec(vector_sub(origin, no.ip));
		halfway = normalizevec(vector_add(view, light));
		ret = color_add(ret, color_add(
			diffuse_color(no, lum, vector_dot(light, n)),
			spec_color(no.obj, lum,
				pow(vector_dot(halfway, n), no.obj.shininess))));
	}
	return (ret);
}

float		get_int_one_obj(t_ray ray, t_obj obj)
{
	t_ray	img_ray;
	float	dist;
	t_pret	poly;

	img_ray = imaginary_ray(ray, obj.transform);
	if (obj.type == 0)
		dist = sphere_dist(img_ray, obj);
	if (obj.type == 1)
		dist = cylindre_dist(img_ray, obj);
	if (obj.type == 2)
		dist = plane_dist(obj, ray);
	if (obj.type == 3)
		dist = cone_dist(img_ray, obj);
	if (obj.type == 4)
		dist = triangle_dist(ray, *obj.faces);
	if (obj.type == 5 || obj.type == 6)
	{
		poly = polygone_dist(ray, obj);
		dist = poly.dist;
	}
	if (obj.type == 7)
		dist = circle_dist(ray, obj);
	if (obj.type == 8)
		dist = quadrics_dist(ray, obj);
	return (dist);
}
