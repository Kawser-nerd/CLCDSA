using System;
using System.Linq;

namespace abc017_3
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            long[] imos = new long[100010];
            long sum = 0;
            for (int i = 0; i < x[0]; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                imos[a[0] - 1] += a[2]; imos[a[1]] -= a[2]; sum += a[2];
            }
            long min = long.MaxValue; long now = 0;
            for (int i = 0; i < x[1]; i++)
            {
                now += imos[i];
                min = Math.Min(min, now);
            }
            Console.WriteLine(sum - min);
        }
    }
}