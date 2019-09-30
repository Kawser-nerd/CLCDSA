using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC061_B();
        }

        static void ABC061_B()
        {
            var NM = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var road = new int[51, 51];

            for (var i = 1; i <= NM[1]; i++)
            {
                var ab = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                road[ab[0], ab[1]] += 1;
                road[ab[1], ab[0]] += 1;
            }

            for (var i = 1; i <= NM[0]; i++)
            {
                var count = 0;
                for (var j = 1; j <= NM[0]; j++)
                {
                    if (road[i, j] > 0)
                        count += road[i, j];
                }
                Console.WriteLine(count);
            }
        }
    }
}