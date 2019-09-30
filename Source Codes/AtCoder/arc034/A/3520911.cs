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
        var result = 0d;
        for(var i = 0; i < num; i++)
        {
            var r = 0d;
            var input = Array.ConvertAll(ReadLine().Split(' '), double.Parse);
            for (var j = 0; j < 4; j++) r += input[j];
            r += input[4] * 11 / 90;
            if (result < r) result = r;
        }
        WriteLine(result);
    }
}