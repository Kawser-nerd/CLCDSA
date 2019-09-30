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
        var input1 = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var input2 = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var a1 = new[] { 0, 0, 1, 1, 2, 2 };
        var a2 = new[] { 1, 2, 0, 2, 0, 1 };
        var a3 = new[] { 2, 1, 2, 0, 1, 0 };
        var result = 0;    
        for(var i = 0; i < 6; i++)
        {
            var w = (input1[0] / input2[a1[i]]) *
                (input1[1] / input2[a2[i]]) *
                (input1[2] / input2[a3[i]]);
            if (result < w) result = w;
        }
        WriteLine(result);
    }
}