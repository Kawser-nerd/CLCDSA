using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var ab = Console.ReadLine().Split(' ');
            var a = int.Parse(ab[0]);
            var b = int.Parse(ab[1]);

            Console.WriteLine((a - 1) * (b - 1));
        }
    }
}