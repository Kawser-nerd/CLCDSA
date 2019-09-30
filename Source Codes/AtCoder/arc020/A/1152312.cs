using System;
using System.Linq;

namespace arc020_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            x[0] = Math.Abs(x[0]);
            x[1] = Math.Abs(x[1]);
            if (x[0] < x[1])
            {
                Console.WriteLine("Ant");
            }
            else if (x[0] > x[1])
            {
                Console.WriteLine("Bug");
            }
            else
            {
                Console.WriteLine("Draw");
            }
        }
    }
}