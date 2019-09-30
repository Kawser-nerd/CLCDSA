using System;
using System.Linq;

namespace arc041_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int k = int.Parse(Console.ReadLine());
            Console.WriteLine(x[0] + x[1] - Math.Abs(x[1] - k));
        }
    }
}