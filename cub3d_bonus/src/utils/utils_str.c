#include <cub.h>

/// Returns `true` if string `s` ends with string `needle`
bool	ft_endswith(const char *s, const char *needle)
{
	const size_t	len = ft_strlen(s);
	const size_t	nlen = ft_strlen(needle);
	const char		*cur;

	if (nlen > len)
		return (false);
	cur = s + len - nlen;
	return (ft_strcmp(cur, needle) == 0);
}
