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
        var des = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var jan = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var result = 0;
        for (var i = 0; i < 7; i++) result += Max(des[i], jan[i]);
        WriteLine(result);
    }
}