/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:31:28 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/04/18 12:32:33 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>

# include "world.h"
# include "shapes.h"
# include "helpers.h"
# include "camera.h"

# define EPSILON 0.00001

t_sphere	*sphere_stub(void);
t_bool		compare_spheres(t_sphere *a, t_sphere *b);
t_world		world_stub(void);
t_world		default_world(void);
t_bool		compare_tuples(t_tuple a, t_tuple b);

#endif
