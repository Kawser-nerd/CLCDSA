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
        if (nab[1] > nab[2]) { WriteLine(0);return; }
        if (nab[0] == 1 && nab[1] == nab[2]) { WriteLine(1);return; }
        else if (nab[0] == 1) { WriteLine(0);return; }

        WriteLine((long)(nab[0] - 2) * (nab[2] - nab[1]) + 1);
    }
}