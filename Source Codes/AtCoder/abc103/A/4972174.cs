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
            var a = new int[3];
            for (int i = 0; i < a.Length; i++)
                a[i] = int.Parse(strs[i]);

            Console.WriteLine(a.Max() - a.Min());
        }
    }
}