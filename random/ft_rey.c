#include <unistd.h>

void	ft_rey(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (str[i] <= 90 && str[i] >= 65)
			str[i] += 32;
		else if (str[i] <= 122 && str[i] >= 97)
			str[i] -= 32;
		write(1, &str[i], 1);
		i--;
	}
}

int main ()
{
	ft_rey("helLo");
return 0;
}
