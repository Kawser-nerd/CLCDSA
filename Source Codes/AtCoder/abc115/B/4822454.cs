using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC115_B();
        }

        static void ABC115_B()
        {
            var N = int.Parse(Console.ReadLine());

            var P = new List<int>();
            for (var n = 0; n < N; n++)
                P.Add(int.Parse(Console.ReadLine()));

            var ordered = P.OrderByDescending(x => x).ToList();
            var max = ordered[0];
            ordered.RemoveAt(0);
            Console.WriteLine((max / 2) + ordered.Sum());
        }
    }
}