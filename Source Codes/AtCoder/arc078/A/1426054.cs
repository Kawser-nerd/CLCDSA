//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class Test
{
    public static void Main()
    {
        var N = long.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();

        var sum = a.Sum();
        var x = 0L;
        var minDif = Int64.MaxValue;  // ??1????

        for (int i = 0; i < N - 1; i++)
        {
            x += a[i];
            minDif = Math.Min(minDif, Math.Abs((sum - x) - x));
        }

        Console.WriteLine(minDif);
    }
}