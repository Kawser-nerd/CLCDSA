using System;
using System.Linq;

namespace arc067_b
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long ret = 0;
            for (int i = 1; i < a[0]; i++)
            {
                ret += Math.Min(a[2], (x[i] - x[i - 1]) * a[1]);
            }
            Console.WriteLine(ret);
        }
    }
}