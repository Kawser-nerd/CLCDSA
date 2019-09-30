using System;
using System.Linq;

namespace abc086_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            Console.WriteLine(((x[0] * x[1]) % 2 == 0) ? "Even" : "Odd");
        }
    }
}