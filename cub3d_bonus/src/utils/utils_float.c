#include <cub.h>

/// Ensures value `val` is in between `min` and `max`, \returns adjusted value
float	fclamp(float val, float min, float max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

/// Return `true` if `val` lies in between `min` and `max` (inclusively)
int	fbetw(float val, float min, float max)
{
	return (val >= min && val <= max);
}
