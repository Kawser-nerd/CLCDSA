using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC110_A();
        }

        static void ABC110_A()
        {
            var ABC = Console.ReadLine().Split(' ').Select(int.Parse).OrderByDescending(x => x).ToArray();
            Console.WriteLine((ABC[0] * 10) + ABC[1] + ABC[2]);
        }
    }
}