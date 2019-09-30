using System;
using System.Linq;

namespace arc057_a
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long n = 0;
            if (x[1] == 0)
            {
                Console.WriteLine(2000000000000 - x[0]);
            }
            else
            {
                while (x[0] < 2000000000000)
                {
                    x[0] += 1 + x[1] * x[0];
                    n++;
                }
                Console.WriteLine(n);
            }
        }
    }
}