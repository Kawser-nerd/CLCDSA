using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC112_B();
        }

        static void ABC112_B()
        {
            var NT = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var N = NT[0];
            var T = NT[1];

            var CT = new List<List<int>>();
            for(var n = 1; n <= N; n++)
                CT.Add(Console.ReadLine().Split(' ').Select(int.Parse).ToList());

            var count = CT.Where(x => x[1] <= T).Count();
            Console.WriteLine(count == 0 ? "TLE" : CT.Where(x => x[1] <= T).Min(x => x[0]).ToString());
        }
    }
}