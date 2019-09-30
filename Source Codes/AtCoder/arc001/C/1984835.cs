using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] input = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
        int a = Math.Abs(input[1] - input[0]);
        Console.WriteLine(a / 10 + new int[10] { 0, 1, 2, 3, 2, 1, 2, 3, 3, 2 }[a % 10]);
    }
}