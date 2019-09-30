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
        var lo = input[0];
        var w = input[1];
        var sp = input[2];
        var st = input[3];
        var o = input[4];
        if (st < o)
        {
            var t1 = (double)(o - st) / (sp + w);
            var t2 = sp <= w ? t1 : (double)(st + lo-o) / (sp - w);
            WriteLine(Min(t1, t2));
        }
        else
        {
            var t1 = (double)(lo + o - st) / (sp + w);
            var t2 = sp <= w ? t1 : (double)(st - o) / (sp - w);
            WriteLine(Min(t1, t2));
        }
    }
}