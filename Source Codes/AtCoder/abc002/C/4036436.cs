using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();
        int[] a = { int.Parse(cin[0]), int.Parse(cin[1]) };
        int[] b = { int.Parse(cin[2]), int.Parse(cin[3]) };
        int[] c = { int.Parse(cin[4]), int.Parse(cin[5]) };

        Console.WriteLine((double)Math.Abs((b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])) / 2.0);
    }
}