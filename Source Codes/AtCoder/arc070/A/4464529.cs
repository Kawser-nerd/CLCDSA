using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
using static System.Math;

class Program
{
    static void Main()
    {
        long x = long.Parse(Console.ReadLine());
        long n = (long)(-1 + Sqrt(1 + 8 * x)) / 2;
        if (n * (n + 1) / 2 < x) n++;
        Console.WriteLine(n);
    }
}