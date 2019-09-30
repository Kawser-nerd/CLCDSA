using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        int[] changeCount = new int[n];
        int[] revCount = new int[n];
        for (int i = 1; i < s.Length; i++)
        {
            changeCount[i] = changeCount[i - 1] + (s[i - 1] == 'W' ? 1 : 0);
        }
        for (int i = s.Length - 2; i >= 0; i--)
        {
            revCount[i] = revCount[i + 1] + (s[i + 1] == 'E' ? 1 : 0);
        }
        var cost = changeCount.Zip(revCount, (x, y) => x + y).ToArray();
        Console.WriteLine(cost.Min());
    }
}