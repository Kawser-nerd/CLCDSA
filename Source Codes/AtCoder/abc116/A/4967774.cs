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
            var ab = int.Parse(strs[0]);
            var bc = int.Parse(strs[1]);

            Console.WriteLine(ab * bc / 2);
        }
    }
}