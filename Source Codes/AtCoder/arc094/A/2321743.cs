using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] abc = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
        //0 0 0 -> 0
        //1 0 0 -> 1
        //1 1 0 -> 2
        int count = 0;
        int diff = abc.Max() * 3 - abc.Sum();
        if (diff % 2 == 1)
        {
            diff -= 1;
            count += 2;
        }
        count += diff / 2;
        Console.WriteLine(count);
    }
}