#include <cub.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE	128

/// Reads through file `path` and returns its length
int	ft_filelen(char *path)
{
	int		fd;
	char	buffer[BUFSIZE];
	int		readres;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERR);
	len = 0;
	while (1)
	{
		readres = read(fd, buffer, BUFSIZE);
		if (readres <= 0)
			break ;
		len += readres;
	}
	close(fd);
	if (readres < 0)
		return (ERR);
	return (len);
}

/// Return file `path` as string, setting `datalen` to the number of bytes
/// in the file
char	*ft_fileload(char *path, int *datalen)
{
	const int	len = ft_filelen(path);
	int			fd;
	int			readres;
	int			pos;
	char		*data;

	data = ft_xmalloc(sizeof(char) * (len + 1 + BUFSIZE));
	data[len] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (datalen)
		*datalen = len;
	pos = 0;
	while (1)
	{
		readres = read(fd, &data[pos], BUFSIZE);
		if (readres <= 0)
			break ;
		pos += readres;
	}
	close(fd);
	if (readres < 0)
		return (free(data), NULL);
	return (data);
}
