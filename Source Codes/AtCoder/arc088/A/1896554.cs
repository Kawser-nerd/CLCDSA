using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        long[] XY = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        int count = 0;
        long num = XY[0];
        while (num <= XY[1])
        {
            num *= 2;
            count++;
        }
        Console.WriteLine(count);
    }
}