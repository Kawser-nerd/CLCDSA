using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = Console.ReadLine();
            if (N == "1")
            {
                Console.WriteLine("Hello World");
            }
            else
            {
                var A = int.Parse(Console.ReadLine());
                var B = int.Parse(Console.ReadLine());

                Console.WriteLine(A + B);
            }
        }
    }
}