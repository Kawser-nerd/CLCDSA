using System;
using System.Linq;

namespace arc062_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[] hyou = new long[] { 1, 1 };
            for (int i = 0; i < n; i++)
            {
                long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
                long j = Math.Max((hyou[0] + x[0] - 1) / x[0], (hyou[1] + x[1] - 1) / x[1]);
                hyou[0] = x[0] * j; hyou[1] = x[1] * j;
            }
            Console.WriteLine(hyou.Sum());
        }
    }
}