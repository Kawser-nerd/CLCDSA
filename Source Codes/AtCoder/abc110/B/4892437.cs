using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC110_B();
        }

        static void ABC110_B()
        {
            var NMXY = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var N = NMXY[0];
            var M = NMXY[1];
            var X = NMXY[2];
            var Y = NMXY[3];

            var xn = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var ym = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var war = true;
            foreach (var z in xn.Concat(ym))
            {
                if (z > X && z <= Y && xn.All(x => x < z) && ym.All(y => y >= z))
                {
                    war = false;
                    break;
                }
            }
            Console.WriteLine(war ? "War" : "No War");
        }
    }
}