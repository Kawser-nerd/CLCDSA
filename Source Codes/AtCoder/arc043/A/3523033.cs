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
        var input = Array.ConvertAll(ReadLine().Split(' '), double.Parse);
        var num = (int)input[0];
        var ave = input[1];
        var range = input[2];
        var sc = new double[num];
        for (var i = 0; i < num; i++) sc[i] = ToDouble(ReadLine());
        var a = sc.Average();
        var b = sc.Max() - sc.Min();
        if (b == 0) { WriteLine(-1); return; }
        var p = range / b;
        var q = ave-p * a ;
        WriteLine($"{p} {q}");
    }
}