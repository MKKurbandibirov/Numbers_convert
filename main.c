#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str);
void	process_for_ones(char *num, char **result);
void	final(char *n, char **result);
int		str_len(char *num);
char	*add_zero(char *num);
void	validator(char *str, char **result);
int		dict_validate(char **dict);
extern char	g_buffer[4000];

int	file_len_checker(char *path)
{
	int		fd;
	int		size;
	int		len;
	char	buf[4098];

	size = 0;
	len = 0;
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		len = read(fd, buf, 4097);
		while (len > 0)
		{
			size += len;
			len = read(fd, buf, 4097);
		}
		close(fd);
	}
	return (size);
}

char	**split_str(char *path)
{
	char	*temp;
	int		fd;
	int		len;
	char	**result;

	len = 0;
	fd = 0;
	result = NULL;
	temp = (char *)malloc(sizeof(char) * file_len_checker(path));
	if (temp)
	{
		fd = open(path, O_RDONLY);
		if (fd != -1)
		{
			len = read(fd, temp, file_len_checker(path));
			close(fd);
		}
	}
	temp[file_len_checker(path)] = '\0';
	result = ft_split(temp);
	free(temp);
	return (result);
}

void	convert(char *path, char *num, int fd)
{
	char	**result;

	result = split_str(path);
	if (dict_validate(result))
		validator(num, result);
	else
		write(2, "Dict Error\n", 11);
	close(fd);
	free(result);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
		if (fd != -1)
			convert("numbers.dict", argv[1], fd);
		else
			write(2, "Dict Error\n", 11);
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
			convert(argv[1], argv[2], fd);
		else
			write(2, "Dict Error\n", 11);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
