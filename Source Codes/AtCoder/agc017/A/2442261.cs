using System;
using System.Linq;
namespace AGC017A
{
    class Program
    {
        static void Main()
        {
            long[] a;
            long n, p;
            a = Console.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
            n = a[0];
            p = a[1];
            a = Console.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
            for (long i = 0; i < n; i++)
                a[i] %= 2;
            long even = a.Count(s => s == 0);
            long odd = n - even;
            Comb c = new Comb(odd);
            long ans = 0;
            for (int i = 0; i <= odd / 2; i++)
                ans += c.CalcComb(odd, 2 * i);
            ans *= (long)Math.Pow(2, even);
            if (p == 0)
                Console.WriteLine(ans);
            else
                Console.WriteLine((long)Math.Pow(2, n) - ans);
        }
    }
    class Comb
    {
        long[,] c;
        public Comb(long n)
        {
            c = new long[n + 1, n + 1];
            c[0, 0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    try { c[i, j] += c[i - 1, j - 1]; } catch { }
                    try { c[i, j] += c[i - 1, j]; } catch { }
                }
            }
        }
        public long CalcComb(long a, long b)
        {
            return c[a, b];
        }
    }
}