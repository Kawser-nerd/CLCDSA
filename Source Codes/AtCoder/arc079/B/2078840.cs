using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    public static void Main()
    {
        Console.WriteLine(50);
        long n = long.Parse(Console.ReadLine());
        long[] a = new long[50];
        long baseNum = n / 50 + 49;
        long decr = n % 50;
        for (int i = 0; i < 50; i++)
        {
            if (i < decr)
            {
                a[i] = baseNum + 50 - decr + 1;
            }
            else
            {
                a[i] = baseNum - decr;
            }
        }
        Console.WriteLine(string.Join(" ", a));
    }
}