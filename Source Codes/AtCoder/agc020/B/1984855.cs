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
            long[] min = new long[n]; long[] max = new long[n];
            min[n - 1] = x[n - 1]; max[n - 1] = x[n - 1] * 2 - 1;
            if (x[n - 1] == 2)
            {
                bool flag = true;
                for (long i = n - 1; i > 0; i--)
                {
                    if ((min[i] - 1) / x[i - 1] == max[i] / x[i - 1]) flag = false;
                    min[i - 1] = ((min[i] - 1) / x[i - 1] + 1) * x[i - 1];
                    max[i - 1] = (max[i] / x[i - 1] + 1) * x[i - 1] - 1;
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