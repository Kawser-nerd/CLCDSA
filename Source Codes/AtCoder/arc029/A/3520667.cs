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
        var times = new int[num];
        for (var i = 0; i < num; i++) times[i] = ToInt32(ReadLine());
        var result = int.MaxValue;
        if (num == 1) { WriteLine(times[0]);return; }
        for (var i = 0; i < num; i++)
        {
            var r1 = times[i];
            var r2 = 0;
            for (var j = 0; j < num; j++)
                if (j != i) r2 += times[j];
            if (result > Max(r1, r2)) result = Max(r1, r2);
        }
        if (num < 4) { WriteLine(result); return; }
        var a1 = new[] { 0, 0,0};
        var a2 = new[] { 1, 3,2};
        var a3 = new[] { 2, 1,1};
        var a4 = new[] { 3, 2,3};
        for(var i = 0; i < 3; i++)
        {
            var r1 = times[a1[i]] + times[a2[i]];
            var r2 = times[a3[i]] + times[a4[i]];
            if (result > Max(r1, r2)) result = Max(r1, r2);
        }
        WriteLine(result);
    }
}