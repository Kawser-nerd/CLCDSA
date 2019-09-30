using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC106_A();
        }

        static void ABC106_A()
        {
            var AB = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            Console.WriteLine((AB[0] - 1) * (AB[1] - 1));
        }
    }
}