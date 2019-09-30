using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var ni = Console.ReadLine().Split(' ');
            var n = int.Parse(ni[0]);
            var i = int.Parse(ni[1]);
            Console.WriteLine(n - i + 1);
        }
    }
}