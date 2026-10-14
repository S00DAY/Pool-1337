#include <stdio.h>

int main(int argc, char **argv)
{
    int freq[26] = {0};
    int i;

    if (argc != 2)
        return (1);
    i = 0;
    while (argv[1][i])
    {
        freq[argv[1][i] - 'a']++;
        i++;
    }
    i = 0;
    while (i < 26)
    {
        if (freq[i])
            printf("%d%c",freq[i] , i + 'a');
        i++;
    }
    return (0);
}
