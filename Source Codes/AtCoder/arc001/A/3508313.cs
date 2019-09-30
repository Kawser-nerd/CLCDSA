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
        var a = ReadLine();
        var str = ReadLine();
        var s = new int[4];
        s[0] = str.Count(c => c == '1');
        s[1] = str.Count(c => c == '2');
        s[2] = str.Count(c => c == '3');
        s[3] = str.Count(c => c == '4');
        WriteLine($"{s.Max()} {s.Min()}");
    }
}