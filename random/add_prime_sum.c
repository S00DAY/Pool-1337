#include <unistd.h>

int main(int ac, char **av)
{
	int	i;
	char	count;

	if (ac == 2)
	{
		i = 0;
		count = 0;
		while (i > 0)
		{
			if (av[1][i] % 2 == 0)
				count = count + av[1][i];
			i--;
		}
		write(1, &count, 3);
		write(1,"\n",1);
	}else
	{
		write(1, "0\n",2);
	}
}
