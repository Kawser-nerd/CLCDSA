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
        var abc = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for(var i=0;i<3;i++)
            if (abc[i] % 2 == 0) { WriteLine(0);return; }
        Array.Sort(abc);
        WriteLine((long)abc[1] * abc[0]);
    }
}