#include <vector.h>
#include <math.h>
#include <stdio.h>

/* ===== vec ===== */
t_vec	vec(float x, float y)
{
	return ((t_vec){x, y});
}

void	vec_print(t_pt *p)
{
	printf("vec: %5.1f %5.1f\n", p->x, p->y);
}

t_vec	vec_from_vec3(t_vec3 *v)
{
	return (vec(v->x, v->y));
}
