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
        var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ho = input[0];
        var minu = input[1];
        WriteLine(18 * 60 - (ho * 60 + minu));
    }
}