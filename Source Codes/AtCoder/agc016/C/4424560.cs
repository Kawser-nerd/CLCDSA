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
        var HWhw = Console.ReadLine().Split().Select(int.Parse).ToList();
        if (HWhw[0] % HWhw[2] == 0 && HWhw[1] % HWhw[3] == 0)
        {
            Console.WriteLine("No");
            return;
        }
        Console.WriteLine("Yes");
        Console.WriteLine(string.Join("\n", Enumerable.Repeat(0, HWhw[0]).Select((_, indh) => string.Join(" ", Enumerable.Repeat(0, HWhw[1]).Select((__, indw) => indh % HWhw[2] == 0 && indw % HWhw[3] == 0 ? 999999999 : (indh + 1) % HWhw[2] == 0 && (indw + 1) % HWhw[3] == 0 ? -1000000000 : 0)))));
    }
}