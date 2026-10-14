#include <stdio.h>

int main(void)
{
	char str[5] = "Hello"; // String dyal 5 bytes (بلا '\0')
	int i = 0;

	// Ghadi y-bqa y-qra ḥtal index 10 (fout l-bound dyal array)
	while (i <= 5)
	{
		printf("%c\n", str[i]);
		i++;
	}
	return (0);
}
