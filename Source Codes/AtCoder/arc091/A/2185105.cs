using System;
using System.Linq;

namespace arc091_a
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            if (x.Min() == 2) Console.WriteLine(0);
            else Console.WriteLine(Math.Max(1,x[0] - 2) * Math.Max(1,x[1] - 2));
        }
    }
}