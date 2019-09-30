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
            var A = int.Parse(strs[0]);
            var B = int.Parse(strs[1]);

            if (A % 2 == 1 && B % 2 == 1)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
    }
}