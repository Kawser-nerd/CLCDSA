using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        double[] n = Console.ReadLine().Split().Select(double.Parse).ToArray();
        Console.WriteLine((n[0] / 100) * (n[0] / 100) * n[1]);
    }
}