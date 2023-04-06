/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:30:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/04/05 20:54:54 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"

typedef struct s_isect_points
{
	float	t1;
	float	t2;
	float	delta;
}	t_isect_points;

static t_isect_points	calculate_isect_points(t_sphere sphere, t_ray ray);

t_intersection	*intersect(t_sphere sphere, t_ray r)
{
	t_ray			ray;
	t_intersection	*xs;
	t_isect_points	c;

	ray = transform(r, inverted_matrix(sphere.transform));
	c = calculate_isect_points(sphere, ray);
	xs = NULL;
	if (c.delta < 0)
		return (NULL);
	insert_intersection(&xs, intersection(c.t1, sphere));
	insert_intersection(&xs, intersection(c.t2, sphere));
	return (xs);
}

void	set_transform(t_sphere *sphere, t_matrix transform)
{
	sphere->transform = transform;
}

static t_isect_points	calculate_isect_points(t_sphere sphere, t_ray ray)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	t_vector	sphere_to_ray;

	sphere_to_ray = subtract(ray.origin, sphere.origin);
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	delta = (b * b) - 4 * a * c;
	return ((t_isect_points){
		.t1 = (-b - sqrtf(delta)) / (2 * a),
		.t2 = (-b + sqrtf(delta)) / (2 * a),
		.delta = (b * b) - 4 * a * c,
	});
}
