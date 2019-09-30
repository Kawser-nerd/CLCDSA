using System;
using System.Linq;

namespace agc010_b
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long times = x.Sum() / (n * (n + 1) / 2);
            long count = 0; long a = 0;
            bool flag = true;
            for (int i = 0; i < n; i++)
            {
                long dis = x[(i + 1) % n] - x[i];
                if ((times - dis) % n != 0) flag = false;
                count += (times - dis) / n;
                if (i + 1 < n) a += (n - 1 - i) * ((times - dis) / n);
                else a += n * ((times - dis) / n);
            }
            if (flag && count == times && x.Min() >= times && a == x[n - 1]) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }
}