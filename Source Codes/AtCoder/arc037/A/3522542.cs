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
        var sc = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var result = 0;
        for (var i = 0; i < num; i++)
            if (sc[i] < 80) result += 80 - sc[i];
        WriteLine(result);
    }
}