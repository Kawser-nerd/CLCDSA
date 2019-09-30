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
            var N = int.Parse(strs[0]);
            var i = int.Parse(strs[1]);

            Console.WriteLine(N - i + 1);
        }
    }
}