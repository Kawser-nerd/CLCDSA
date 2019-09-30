using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        static long Solve(int N, long[] a)
        {
            long sum = 0;
            while (true)
            {
                Array.Sort(a);
                if (a[N - 1] < N) { return sum; }
                long n = (a[N - 1] - N) / N + 1;
                for (int i = 0; i < N - 1; ++i) { a[i] += n; }
                a[N - 1] -= n * N;
                sum += n;
            }
        }
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            long[] a = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
            Console.WriteLine(Solve(N, a));
        }
    }
}