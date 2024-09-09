#include <cub.h>

t_hitrec	hitnone(void)
{
	return ((t_hitrec){INFINITY, INFINITY,
		vec(INFINITY, INFINITY), vec(0, 0)});
}

void	hitrec_print(t_hitrec *hr)
{
	printf("hitrec: dist=%.2f pos={ %.2f, %.2f }"
		", normal={ %.2f, %.2f }\n", \
		hr->dist, hr->hit.x, hr->hit.y, hr->normal.x, hr->normal.y);
}

void	hitlist_print(t_hitrec *hr)
{
	int	i;

	if (isfinite(hr->dist))
		printf("=== hitlist ===\n");
	i = 0;
	while (i < MAXHITS && isfinite(hr[i].dist))
	{
		hitrec_print(&hr[i]);
		i++;
	}
}

void	hitlist_sort(t_hitrec *hitlist)
{
	bool			swapped;
	t_hitrec		h;
	int				j;

	swapped = true;
	while (swapped)
	{
		swapped = false;
		j = 0;
		while (j + 1 < MAXHITS && isfinite(hitlist[j].dist) && \
				isfinite(hitlist[j + 1].dist))
		{
			if (hitlist[j].dist > hitlist[j + 1].dist)
			{
				h = hitlist[j];
				hitlist[j] = hitlist[j + 1];
				hitlist[j + 1] = h;
				swapped = true;
			}
			j++;
		}
	}
}
