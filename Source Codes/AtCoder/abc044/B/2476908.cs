using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        int[] count = new int[26];
        foreach (var c in s)
        {
            count[c - 'a']++;
        }
        Console.WriteLine(count.All(x => x % 2 == 0) ? "Yes" : "No");
    }
}