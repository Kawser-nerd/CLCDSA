using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC100_B();
        }

        static void ABC100_B()
        {
            var DN = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var D = DN[0];
            var N = DN[1] == 100 ? DN[1]+1 : DN[1];
            Console.WriteLine(Math.Pow(100, D) * N);
        }
    }
}