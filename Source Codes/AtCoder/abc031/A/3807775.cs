using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{

    class Program
    {

        static void Main(string[] args)
        {

            string[] input = Console.ReadLine().Split(' ');

            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);

            Console.WriteLine(Math.Max((a + 1) * b, (b + 1) * a));

        }
    }
}