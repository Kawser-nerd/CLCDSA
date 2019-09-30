using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        static long[] Solve(long K)
        {
            long N = (K + 49) / 50;
            long[] a = Enumerable.Repeat(N + 49, 50).ToArray();
            for (long i = N * 50; i > K; --i)
            {
                for (int j = 0; j < 49; ++j) { ++a[j]; }
                a[49] -= 50;
                Array.Sort(a);
            }
            return a;
        }
        static void Main(string[] args)
        {
            long K = long.Parse(Console.ReadLine());
            Console.WriteLine("50");
            Console.WriteLine(string.Join(" ", Solve(K)));
        }
    }
}