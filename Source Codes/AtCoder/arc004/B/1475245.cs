using System;
using System.Linq;

namespace arc004_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[] d = new long[n];
            for (int i = 0; i < n; i++)
            {
                d[i] = int.Parse(Console.ReadLine());
            }
            Console.WriteLine(d.Sum());
            Console.WriteLine(Math.Max(0, d.Max() - (d.Sum() - d.Max())));
        }
    }
}