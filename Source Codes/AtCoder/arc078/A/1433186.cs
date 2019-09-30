using System;
using System.Linq;

namespace arc078_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long ret = long.MaxValue;
            long flont = 0;
            long back = x.Sum();
            for (int i = 0; i < n - 1; i++)
            {
                flont += x[i];
                back -= x[i];
                ret = Math.Min(ret, Math.Abs(flont - back));
            }
            Console.WriteLine(ret);
        }
    }
}