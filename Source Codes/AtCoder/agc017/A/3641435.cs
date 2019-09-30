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
        var np = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var odd = ar.Count(v => v % 2 == 1);
        var even = np[0] - odd;
        if (odd == 0 && np[1] == 1) { WriteLine(0);return; }
        WriteLine(odd==0?(long)Pow(2,np[0]):(long)Pow(2, np[0] - 1));
    }
}