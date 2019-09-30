using System;
using System.Collections.Generic;
using System.Linq;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long[] a = new long[n + 1];
            for (int i = 0; i < n; i++) a[i + 1] = x[i];
            long[] min = new long[n + 1]; long[] max = new long[n + 1];
            min[n] = 2; max[n] = 2;
            if (a[n] == 2)
            {
                bool flag = true;
                for (long i = n; i > 0; i--)
                {
                    if ((min[i] - 1) / a[i] == max[i] / a[i]) flag = false;
                    min[i - 1] = ((min[i] - 1) / a[i] + 1) * a[i];
                    max[i - 1] = (max[i] / a[i] + 1) * a[i] - 1;
                }
                Console.WriteLine(flag ? min[0] + " " + max[0] : "-1");
            }
            else
            {
                Console.WriteLine(-1);
            }
        }
    }
}