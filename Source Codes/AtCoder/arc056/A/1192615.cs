using System;
using System.Linq;

namespace arc056_a
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            Console.WriteLine(Math.Min((x[2] / x[3]) * x[1] + (x[2] % x[3]) * x[0], (x[2] / x[3] + 1) * x[1]));
        }
    }
}