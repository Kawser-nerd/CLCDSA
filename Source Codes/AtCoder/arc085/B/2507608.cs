using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] nzw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        if(a.Length != 1) Console.WriteLine(Max(Abs(nzw[2] - a.Last()), Abs(a[a.Length - 2] - a[a.Length - 1])));
        else Console.WriteLine(Abs(nzw[2] - a.Last()));
    }
}