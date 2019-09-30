using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC102_B();
        }

        static void ABC102_B()
        {
            var N = int.Parse(Console.ReadLine());
            var A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            Console.WriteLine(A.Max() - A.Min());
        }
    }
}