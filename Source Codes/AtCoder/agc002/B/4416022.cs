using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using System.Collections;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;


class P
{
    static void Main()
    {
        var nm = Console.ReadLine().Split().Select(int.Parse).ToList();
        int[] count = Enumerable.Repeat(1, nm[0]).ToArray();
        bool[] isPossible = new bool[nm[0]];
        isPossible[0] = true;
        for (int i = 0; i < nm[1]; i++)
        {
            var xy = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToList();
            count[xy[0]]--;
            count[xy[1]]++;
            isPossible[xy[1]] |= isPossible[xy[0]];
            if (count[xy[0]] == 0) isPossible[xy[0]] = false;
        }
        Console.WriteLine(isPossible.Count(x => x));
    }
}