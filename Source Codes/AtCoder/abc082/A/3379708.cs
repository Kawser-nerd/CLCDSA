using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            var a = input[0];
            var b = input[1];

            var c = (a + b+1) / 2;

            Console.WriteLine(c);

        }

    }

}