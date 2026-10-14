#include <unistd.h>

int is_palindrome(char *str,int i,int j)
{
	while(i < j)
	{
		if(str[i] != str[j])
		{
			return 0;
		}else{
			i++;
			j--;
		}
	}
	return 1;
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	int indx;
	int best;
	int is;
	int tmp=0;
	i = 0;
	j = 1;
	indx = 0;
	best = 0;
	if(argc == 2)
	{
		while(argv[1][i])
				i++;
		if(i == 1)
		{
			i--;
			write(1,&argv[1][i],1);
			write(1,"\n",1);
			return 0;
		}
		i = 0;
		while(argv[1][j])
			j++;
		j--;
		tmp = j;
		while(argv[1][i])
		{
			while(argv[1][i] != argv[1][j])
					j--;
			if(argv[1][i] == argv[1][j] && i != j)
			{
				is = is_palindrome(argv[1],i,j);
				if(is == 1)
				{
					if(best <= (j - i) + 1)
					{	
						best = (j - i) + 1;
						indx = i;
						i++;
						j = tmp;
					}else{
						i++;
						j--;
					}
				}else if(is == 0){
					j--;
				}
			}else if(j == i)
			{
				i++;
				j = tmp;
			}
		}
		if(best == 0)
		{
		write(1,&argv[1][0],1);
			write(1,"\n",1);
			return 0;
		}
		while(best > 0)
		{
			write(1,&argv[1][indx],1);
			indx++;
			best--;
		}
	}else{
		write(1,"wrong number of arguments",25);
	}
		write(1,"\n",1);

	return (0);
}

