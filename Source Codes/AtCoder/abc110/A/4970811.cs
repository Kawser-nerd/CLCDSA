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
            var C = int.Parse(strs[2]);

            var sum = new int[3];
            sum[0] = A * 10 + B + C;
            sum[1] = A + B * 10 + C;
            sum[2] = A + B + C * 10;

            Console.WriteLine(sum.Max());
        }
    }
}