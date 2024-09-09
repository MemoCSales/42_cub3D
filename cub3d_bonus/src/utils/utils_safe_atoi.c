#include <cub.h>

// Function to remove newline character
void	remove_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
}

// Function to check for non-digit characters
int	has_non_digit_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// Function to check if the number is within the range 0-255
int	is_in_range(int num)
{
	return (num >= 0 && num <= 255);
}
