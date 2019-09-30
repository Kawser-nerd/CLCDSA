using System;
using System.Linq;

namespace arc053_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int a = 0;
            if (x[0] >= 2)
            {
                a += (x[0] - 1) * x[1];
            }
            if (x[1] >= 2)
            {
                a += x[0] * (x[1] - 1);
            }
            Console.WriteLine(a);
        }
    }
}