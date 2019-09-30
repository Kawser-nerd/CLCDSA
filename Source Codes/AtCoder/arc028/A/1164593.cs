using System;
using System.Linq;

namespace arc028_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            x[0] %= x[1] + x[2];
            if (x[0] == 0)
            {
                Console.WriteLine("Bug");
            }
            else
            {
                Console.WriteLine(x[0] <= x[1] ? "Ant" : "Bug");
            }
        }
    }
}