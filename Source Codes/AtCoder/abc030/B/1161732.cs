using System;
using System.Linq;

namespace abc030_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int time = x[0] * 60 + x[1];
            double clock = time * 5.5 % 360;
            clock = Math.Min(clock, 360 - clock);
            Console.WriteLine(clock);
        }
    }
}