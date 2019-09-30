using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        var a = Console.ReadLine().Split().Select(int.Parse).ToList();
        var any = a.Where(x => 3200 <= x).Count();
        var colors = a.Where(x => x < 3200).Select(x => x / 400).Distinct().Count();
        Console.WriteLine($"{Max(1, colors)} {colors + any}");
    }
}