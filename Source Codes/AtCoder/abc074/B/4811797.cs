using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(ABC074_B());
        }

        static int ABC074_B()
        {
            var N = int.Parse(Console.ReadLine());
            var K = int.Parse(Console.ReadLine());
            var xi = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            var sum = 0;
            for (var i = 0; i < N; i++)
            {
                var a = xi[i] * 2;
                var b = (K - xi[i]) * 2;
                sum += Math.Min(a, b);
            }
            return sum;
        }
    }
}