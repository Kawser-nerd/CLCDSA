using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] hm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine((new DateTime(2000, 1, 1, 18, 00, 00) - new DateTime(2000, 1, 1, hm[0], hm[1], 00)).TotalMinutes);
    }
}