using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long count = 0;
        long nicho = 2000000000000;
        if (a[1] == 0)
        {
            count = nicho - a[0];
        }
        else
        {
            long t = a[0];
            while (t < nicho)
            {
                t += (t * a[1] + 1);
                //Console.WriteLine(t);
                count++;
            }
        }
        Console.WriteLine(count);
    }
}