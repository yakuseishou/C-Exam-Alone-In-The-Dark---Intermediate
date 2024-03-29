/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:43:52 by kchen2            #+#    #+#             */
/*   Updated: 2019/11/12 21:33:27 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

int     *height_right(int *rightheight, int *histogram, int size)
{
    int     max = 0;
    int     i;

    for (i = size - 1; i >= 0; i--)
    {
        rightheight[i] = max;
        if (max < histogram[i])
            max = histogram[i];
    }
    return (rightheight);
}

int    volume_histogram(int *histogram, int size)
{
    if (!size)
        return (0);
    int     rightheight[size];
    int     i;
    int     pre = 0;
    int     res = 0;

    height_right(rightheight, histogram, size);
    for (i = 0; i < size; i++)
    {
        if (histogram[i] > pre)
            pre = histogram[i];
        if ((min(pre, rightheight[i]) - histogram[i]) > 0)
            res += (min(pre, rightheight[i]) - histogram[i]);
    }
    return (res);
}


/* test main */

// #include <stdio.h>

// int		main()
// {
// 	int		a[] = {0, 10, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 8, 0, 0, 0, 0, 9, 0, 0, 0, 2, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 9, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 5, 0, 0, 0, 4, 0, 0, 7, 0, 0, 2, 1, 0};
// 	int		size = sizeof(a) / sizeof(int);

// 	printf("%d\n", volume_histogram(a, size)); // should be 343
// 	return (0);
// }

/* older less optimize version */

// int    volume_histogram(int *histogram, int size)
// {
//     int     i;
//     int     n;
//     int     res = 0;
//     int     flag = 0;
    
//     while (!flag)
//     {
//         i = 0;
//         n = 0;
//         flag = 1;
//         while (i < size && histogram[i] == 0)
//             i++;
//         while (i < size)
//         {
//             if (histogram[i] > 0)
//             {
//                 histogram[i]--;
//                 res += n;
//                 n = 0;
//                 flag = 0;
//             }
//             else if (histogram[i] == 0)
//                 n++;
//             i++;
//         }
//     }
//     return (res);
// }