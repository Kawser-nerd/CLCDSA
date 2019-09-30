using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC109_A();
        }

        static void ABC109_A()
        {
            var AB = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            Console.WriteLine((AB[0] * AB[1]) % 2 == 0 ? "No" : "Yes");
        }
    }
}