#include <cub.h>

bool	rect_inside(t_rect *rect, t_pt pt)
{
	return (pt.x >= rect->tl.x && pt.x <= rect->br.x && \
			pt.y >= rect->tl.y && pt.y <= rect->br.y);
}
