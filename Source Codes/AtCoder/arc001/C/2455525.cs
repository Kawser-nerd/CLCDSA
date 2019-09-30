using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;
class P
{
    static void Main()
    {
        int[] table = { 0, 1, 2, 3, 2, 1, 2, 3, 3, 2 };
        int[] ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int diff = Abs(ab[0] - ab[1]);
        Console.WriteLine(table[diff % 10] + diff / 10);
    }
}