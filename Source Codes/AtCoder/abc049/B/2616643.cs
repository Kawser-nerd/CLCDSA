using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        for (int i = 0; i < hw[0]; i++)
        {
            string s = Console.ReadLine();
            Console.WriteLine($"{s}\n{s}");
        }
    }
}