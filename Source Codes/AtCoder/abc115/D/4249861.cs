using System;
using System.Linq;

namespace ABC115_D
{
    class Program
    {
        static long[] a;
        static long[] p;
        static void Main(string[] args)
        {
            var NX = Console.ReadLine().Split().Select(long.Parse).ToArray();
            var N = NX[0];
            var X = NX[1];

            a = new long[N];
            p = new long[N];
            a[0] = 1;
            p[0] = 1;
            for (int i = 1; i < N; i++)
            {
                a[i] = a[i - 1] * 2 + 3;
                p[i] = p[i - 1] * 2 + 1;
            }

            Console.WriteLine(Calc(N, X));
        }

        static long Calc(long n, long x)
        {
            if (n == 0) return x <= 0 ? 0 : 1;
            else if (x <= 1 + a[n - 1]) return Calc(n - 1, x - 1);
            else return p[n - 1] + 1 + Calc(n - 1, x - 2 - a[n - 1]);
        }
    }
}