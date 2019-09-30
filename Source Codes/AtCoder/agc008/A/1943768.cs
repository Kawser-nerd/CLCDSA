using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int res = 0;
        if (a[0] < 0 && a[1] < 0)
        {
            if (a[0] > a[1])
            {
                res = a[0] - a[1] + 2;
            }
            else
            {
                res = a[1] - a[0];
            }
        }
        else if (a[0] > 0 && a[1] > 0)
        {
            if (a[0] > a[1])
            {
                res = a[0] - a[1] + 2;
            }
            else
            {
                res = a[1] - a[0];
            }
        }
        else
        {
            res = Math.Min(Math.Abs(a[1] + a[0]) + 1, (a[1] - a[0] >= 0 ? a[1] - a[0] : int.MaxValue));
        }
        Console.WriteLine(res);
    }
}