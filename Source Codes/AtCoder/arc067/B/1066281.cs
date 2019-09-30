using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        long[] values = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        long N = values[0];
        long A = values[1];
        long B = values[2];
        long[] X = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        long a = 0;
        long b = N - 1;
        for (int i = 1; i < N; ++i)
        {
            if ((X[i] - X[i - 1]) * A < B)
            {
                a += X[i] - X[i - 1];
                --b;
            }
        }
        Console.WriteLine(a * A + b * B);
    }
}