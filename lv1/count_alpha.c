#include <stdio.h>

int     isdup(char *s, int n, char c)
{
    int     i;

    i = -1;
    while(++i < n)
        if (s[i] == c)
            return (1);
    return (0);
}

void    cnalp(char *s)
{
    int     i;
    int     n;
    int     j;
    int     flag;

    i = -1;
    n = 0;
    flag = 0;
    while(s[++i])
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    i = -1;
    while(s[++i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (!(isdup(s, i, s[i])))
            {
                j = i - 1;
                while (s[++j])
                {
                    if (s[j] == s[i])
                        n++;
                }
                if (flag)
                    printf(", ");
                printf("%d%c", n, s[i]);
                n = 0;
                flag = 1;
            }
        }
    }
}

int     main(int ac, char **av)
{
    if (ac == 2)
        cnalp(av[1]);
    printf("\n");
    return (0);
}