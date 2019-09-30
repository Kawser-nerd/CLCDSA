using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(ABC088_C());
        }

        static string ABC088_C()
        {
            var C = new int[3, 3];
            var x = new int[3];
            var y = new int[3];
            for (var i = 0; i < 3; i++)
            {
                var c = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                C[i, 0] = c[0];
                C[i, 1] = c[1];
                C[i, 2] = c[2];
            }

            x[0] = 0;

            for (var i = 0; i < 3; i++) y[i] = C[0, i] - x[0];
            for (var i = 1; i < 3; i++) x[i] = C[i, 0] - y[0];

            for (var i = 0; i < 3; i++)
            {
                for (var j = 0; j < 3; j++)
                {
                    if (C[i, j] != x[i] + y[j])
                        return "No";
                }
            }
            return "Yes";
        }
    }
}