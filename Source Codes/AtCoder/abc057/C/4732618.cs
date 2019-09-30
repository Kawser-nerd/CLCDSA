using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        long N = long.Parse(Console.ReadLine());
        int m = int.MaxValue;
        for (long i = 1; i * i <= N; i++)
        {
            if (N % i != 0)
                continue;
            m = Math.Min(Math.Max(i, N / i).ToString().Length, m);
        }
        Console.WriteLine(m);
    }
}