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
        var nab = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        WriteLine((nab[2] - nab[1] + 1) % 2 == 0 ? "Borys" : "Alice");
    }
}