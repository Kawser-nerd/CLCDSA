using System;
using System.Linq;
using System.Collections;

namespace Bcs
{
    class Program
    {
        static void Main(string[] args)
        {
            var ar = Console.ReadLine().Split(' ').Select(x=>int.Parse(x)).ToArray();
            var k = int.Parse(Console.ReadLine().Trim());

            var max = ar.Max();
            var sum = ar.Sum() - max;
            sum += (int)(Math.Pow(2, k))* max;

            Console.WriteLine(sum);
        }
    }
}