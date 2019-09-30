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
        var str = ReadLine();
        WriteLine(
            (double)(str.Count(c => c == 'A') * 4 +
            str.Count(c => c == 'B') * 3 +
            str.Count(c => c == 'C') * 2 +
            str.Count(c => c == 'D') * 1
            ) / str.Length
            );
    }
}