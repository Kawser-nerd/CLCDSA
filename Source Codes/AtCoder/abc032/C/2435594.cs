using System;
using System.Linq;

namespace abc032_c
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long[] a = new long[x[0]];
            for (int i = 0; i < x[0]; i++) a[i] = int.Parse(Console.ReadLine());
            if (a.Contains(0)) Console.WriteLine(x[0]);
            else
            {
                int right = 0; long seki = 1; int ret = 0;
                for (int left = 0; left < x[0]; left++)
                {
                    for (right = Math.Max(right, left); right < x[0] && seki * a[right] <= x[1]; right++)
                    {
                        seki *= a[right];
                    }
                    if (a[left] <= x[1]) ret = Math.Max(ret, right - left);
                    seki /= a[left];
                    if (seki == 0) seki = 1;
                }
                Console.WriteLine(ret);
            }
        }
    }
}