using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int t = int.Parse(Console.ReadLine());
        long[] a = new long[t];
        long[] b = new long[t];
        long[] c = new long[t];
        long[] d = new long[t];
        for (int i = 0; i < t; i++)
        {
            string[] input = Console.ReadLine().Split(' ');
            a[i] = long.Parse(input[0]);
            b[i] = long.Parse(input[1]);
            c[i] = long.Parse(input[2]);
            d[i] = long.Parse(input[3]);
        }

        for (int i = 0; i < t; i++)
        {
            if(a[i] < b[i])
            {
                Console.WriteLine("No");
                continue;
            }
            if (b[i] > d[i])
            {
                Console.WriteLine("No");
                continue;
            }
            long gcd = Gcd(b[i], d[i]);
            long tmp = a[i] % b[i];
            if (gcd + c[i] >= b[i] && tmp <= c[i])
            {
                Console.WriteLine("Yes");
                continue;
            }
            else
            {
                Console.WriteLine("No");
                continue;
            }
        }
    }
    public static long Gcd(long a, long b)
    {
        if (a < b)
            // ??????????????
            return Gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
}