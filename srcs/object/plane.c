/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:00:43 by dsusheno          #+#    #+#             */
/*   Updated: 2017/03/24 15:00:52 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	plane_dist2(t_face obj, t_ray r)
{
	float	t_coef;
	float	normal_to_ray;
	t_vec3d	vect_to_point;

	t_coef = -1;
	normal_to_ray = vector_dot(obj.normal, r.dir);
	if (normal_to_ray != 0)
	{
		vect_to_point = vector_sub(obj.vertex->coord, r.origin);
		t_coef = vector_dot(obj.normal, vect_to_point) / normal_to_ray;
	}
	if (t_coef > 0)
		return (t_coef);
	else
		return (-1);
}

float	plane_dist(t_obj obj, t_ray r)
{
	float	t_coef;
	float	normal_to_ray;
	t_vec3d	vect_to_point;
	t_vec3d	normal_rot;

	t_coef = -1;
	normal_rot = rota_vect(obj.normal, obj.transform.rot);
	normal_to_ray = vector_dot(normal_rot, r.dir);
	if (normal_to_ray != 0)
	{
		vect_to_point = vector_sub(obj.transform.transl, r.origin);
		t_coef = vector_dot(normal_rot, vect_to_point) / normal_to_ray;
	}
	if (t_coef > 0)
		return (t_coef);
	else
		return (-1);
}
