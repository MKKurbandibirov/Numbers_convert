#include <stdlib.h>

void	process_for_ones(char *num, char **result);
void	process_for_tens(char *num, char **result);
void	process_for_others(char *num, char **result);
char	*ft_strcat(char *dest, char src);
int		str_len(char *num);

void	double_digit(char *num, char **result)
{
	char	tmp[2];

	if (num[0] == '1' || (num[0] != '0' && num[1] == '0'))
	{
		process_for_tens(num, result);
	}
	else if (num[0] != '1' && num[1] != '0')
	{
		tmp[0] = num[0];
		tmp[1] = '0';
		process_for_tens(tmp, result);
		process_for_ones(&num[1], result);
	}
}

void	three_digit(char *num, char **result, char *power)
{
	char	tmp[2];

	tmp[0] = num[1];
	tmp[1] = num[2];
	if (num[0] == '0')
	{
		double_digit(tmp, result);
	}
	else if (num[0] != '0')
	{
		process_for_ones(&num[0], result);
		process_for_others(power, result);
		double_digit(tmp, result);
	}
}

char	*add_zero(char *num)
{
	int		i;
	int		len;
	char	*new_num;

	len = str_len(num);
	i = -1;
	if (len % 3 == 1)
	{
		new_num = malloc(sizeof(char) * len + 2);
		new_num[0] = '0';
		new_num[1] = '0';
		while (i++ < len)
			new_num[i + 2] = num[i];
	}
	else if (len % 3 == 2)
	{
		new_num = malloc(sizeof(char) * len + 1);
		new_num[0] = '0';
		while (i++ < len)
			new_num[i + 1] = num[i];
	}
	else
		new_num = num;
	return (new_num);
}

char	*powers(int i)
{
	char	*power;
	int		j;

	j = 1;
	power = malloc(sizeof(char) * (i * 3 + 5));
	power[0] = '1';
	while (j < (i * 3 + 4))
	{
		power[j] = '0';
		j++;
	}
	power[j] = '\0';
	return (power);
}

void	final(char *n, char **result)
{
	int		i;
	int		count;
	char	tmp[3];
	int		len;
	char	*power;

	i = 0;
	len = str_len(n);
	count = len / 3;
	while (i < count)
	{
		tmp[0] = n[i * 3];
		tmp[1] = n[i * 3 + 1];
		tmp[2] = n[i * 3 + 2];
		three_digit(tmp, result, "100");
		if (i != count - 1)
		{
			power = powers(count - i - 2);
			if (n[i * 3] != '0' || n[i * 3 + 1] != '0' || n[i * 3 + 2] != '0')
				process_for_others(power, result);
			free(power);
		}
		i++;
	}
}
