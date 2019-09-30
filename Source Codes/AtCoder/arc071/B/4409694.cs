using System;
using System.Linq;

class Program
{
    static long mod = (long)1e9 + 7;

    static long n;
    static long m;
    static long[] x;
    static long[] y;

    static void Main()
    {
        long[] input = Console.ReadLine().Split().Select(long.Parse).ToArray();
        n = input[0];
        m = input[1];
        x = Console.ReadLine().Split().Select(long.Parse).ToArray();
        y = Console.ReadLine().Split().Select(long.Parse).ToArray();

        long x_min = x.Min();
        x = x.Select(s => s - x_min).ToArray();
        long y_min = y.Min();
        y = y.Select(s => s - y_min).ToArray();

        /* y???????? */
        long ys = 0;
        for (int i = 1; i < m; i++)
        {
            ys += i * y[i] % mod;
            ys %= mod;
        }
        for (int i = 0; i < m - 1; i++)
        {
            ys -= (m - 1) * y[i] % mod;
            ys += (ys < 0) ? mod : 0;
            ys %= mod;
        }
        for (int i = 1; i < m - 1; i++)
        {
            ys += i * y[i] % mod;
            ys %= mod;
        }

        /* x???????? */
        long xs = 0;
        for (int i = 1; i < n; i++)
        {
            xs += i * x[i] % mod;
            xs %= mod;
        }
        for (int i = 0; i < n - 1; i++)
        {
            xs -= (n - 1) * x[i] % mod;
            xs += (xs < 0) ? mod : 0;
            xs %= mod;
        }
        for (int i = 1; i < n - 1; i++)
        {
            xs += i * x[i] % mod;
            xs %= mod;
        }

        Console.WriteLine(xs * ys % mod);
    }
}