using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for (var i = 0; i < num; i++)
            ar[i] %= 2;
        WriteLine(ar.Count(v => v == 1) % 2 == 0 ? "YES" : "NO");
    }
}