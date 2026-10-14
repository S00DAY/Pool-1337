#include <unistd.h>

int main(int ac, char **av)
{
	int	endend;
	int	start;
	int	i;

	if (ac == 2)
	{
		endend = 0;
		i = 0;
		while (av[1][endend])
			endend++;
		endend--;
		while (av[1][endend] == ' ' || av[1][endend] == '\t' && endend >= 0)
			endend--;
		start = endend;
		while(av[1][start] != 32 && av[1][start] != 9 && start >= 0)
		{
			start--;
		}
		start++;
		while (start <= endend)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
return 0;
}
