#include <vector.h>

/* ===== vec3 ===== */
t_vec3	vec3(float x, float y, float z)
{
	return ((t_vec3){x, y, z});
}

t_vec3	vec3_from_vec(t_vec	*v)
{
	return (vec3(v->x, v->y, 0));
}

/* ===== ipt ===== */
t_ipt	ipt(int x, int y)
{
	return ((t_ipt){x, y});
}

/* ===== cpt ===== */
t_cpt	cpt(t_color c, int x, int y)
{
	return ((t_cpt){c, ipt(x, y)});
}

/* ===== rect ===== */
t_rect	rect(int x1, int y1, int x2, int y2)
{
	return ((t_rect){ipt(x1, y1), ipt(x2, y2)});
}
