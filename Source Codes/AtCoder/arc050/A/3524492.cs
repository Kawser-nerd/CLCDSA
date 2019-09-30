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
        var strs = ReadLine().Split(' ');
        WriteLine(strs[0].Equals(strs[1], StringComparison.OrdinalIgnoreCase) ? "Yes" : "No");
    }
}