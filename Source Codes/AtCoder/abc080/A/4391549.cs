using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int a = int.Parse(input[1]);
            int b = int.Parse(input[2]);
            if (n * a > b)
            {
                Console.WriteLine(b);
            }
            else
            {
                Console.WriteLine(n * a);
            }
        }
    }
}