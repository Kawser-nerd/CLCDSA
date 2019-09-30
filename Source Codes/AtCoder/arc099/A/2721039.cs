using System;
using System.Linq;

namespace arc099_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.ReadLine();
            x[0] -= x[1];
            Console.WriteLine((x[0] + x[1] - 2) / (x[1] - 1) + 1);
        }
    }
}