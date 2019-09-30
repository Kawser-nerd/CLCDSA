using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var input = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        var one = input[0];
        var cl = input[1];
        var li = input[2];
        var se = input[3];
        long result = (li / se) * cl;
        result += Min(one * (li%se), cl);
        WriteLine(result);
        
    }
}