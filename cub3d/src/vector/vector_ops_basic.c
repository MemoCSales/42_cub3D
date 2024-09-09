#include <vector.h>
#include <math.h>

t_vec	vec_add(t_vec a, t_vec b)
{
	return (vec(a.x + b.x, a.y + b.y));
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	return (vec(a.x - b.x, a.y - b.y));
}

t_vec	vec_scale(t_vec a, float f)
{
	return ((t_vec){f * a.x, f * a.y});
}

float	vec_len(t_vec v)
{
	return (hypot(v.x, v.y));
}
