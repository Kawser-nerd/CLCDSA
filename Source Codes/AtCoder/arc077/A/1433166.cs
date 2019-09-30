using System;
using System.Linq;

namespace arc077_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Array.Reverse(x);
            Console.Write(x[0]);
            for (int i = 2; i < n; i += 2)
            {
                Console.Write(" " + x[i]);
            }
            Array.Reverse(x);
            for (int i = n % 2; i < n; i += 2)
            {
                Console.Write(" " + x[i]);
            }
            Console.WriteLine();
        }
    }
}