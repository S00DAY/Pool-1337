#include <unistd.h>
int main(int ac, char **av)
{
	int i=0,j=0;
	if(ac == 2)
	{
		while(av[1][i])
			i++;
		i--;
		while(i >= 0)
		{
			while(i >= 0 && av[1][i] == 32)
				i--;
			if(i < 0)
				break;
			while(i >= 0 && av[1][i] != 32)
				i--;
			j = i + 1;
			while(av[1][j] && av[1][j] != 32)
			{
				write(1,&av[1][j],1);
				j++;
			}
			write(1," ",1);
		}
	}
	write(1,"\n",1);
	return 0;
}
