using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC101_B();
        }

        static void ABC101_B()
        {
            var N = int.Parse(Console.ReadLine());
            var tmp = N;
            var S = 0;
            while (tmp > 0)
            {
                S += tmp % 10;
                tmp = tmp / 10;
            }

            Console.WriteLine(N % S == 0 ? "Yes" : "No");
        }
    }
}