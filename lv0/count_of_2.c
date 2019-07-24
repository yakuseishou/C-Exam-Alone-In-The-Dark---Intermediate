int     count_of_2(int n)
{
    int     res;
    int     i;
    int     k;

    res = 0;
    i = 1;
    if (n <= 1)
        return (0);
    while(++i <= n)
    {
        if (i % 10 == 2)
            res++;
        k = i;
        while(k /= 10)
        {
            if (k % 10 == 2)
                res++;
        }
    }
    return (res);
}