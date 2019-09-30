using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        ulong m, n, a, b;
        string[] s;
        a = 1;
        b = 1;

        for (int i = 0; i < N; i++)
        {
            s = Console.ReadLine().Split(' ');
            m = ulong.Parse(s[0]);
            n = ulong.Parse(s[1]);
            ulong pa,pb;
            if (a % m == 0)
                pa = a / m;
            else
                pa = a / m + 1;

            if (b % n == 0)
                pb = b / n;
            else
                pb = b / n + 1;

            if (pa > pb)
            {
                a = m * pa;
                b = n * pa;
            }
            else
            {
                a = m * pb;
                b = n * pb;
            }
        }
        Console.WriteLine(a + b);
    }
}