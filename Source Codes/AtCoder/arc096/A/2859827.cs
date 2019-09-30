using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int[] input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int a = input[0];
        int b = input[1];
        int c = input[2];
        int x = input[3];
        int y = input[4];

        long ab = 2 * c * Math.Max(x, y);
        long st = 2 * c * Math.Min(x, y) + a * (x - Math.Min(x, y)) + b * (y - Math.Min(x, y));
        long no = a * x + b * y;

        long ans = Math.Min(ab, Math.Min(st, no));

        Console.WriteLine(ans);

    }
}