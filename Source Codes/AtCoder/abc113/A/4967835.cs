using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var strs = Console.ReadLine().Split();
            var X = int.Parse(strs[0]);
            var Y = int.Parse(strs[1]);

            Console.WriteLine(X + Y / 2);
        }
    }
}