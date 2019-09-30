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
        var nck = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var times = new int[nck[0]];
        for (var i = 0; i < nck[0]; i++)
            times[i] = ToInt32(ReadLine());
        Array.Sort(times);
        var result = 1;
        var time = times[0] + nck[2];
        var pe = 1;
        for(var i = 1; i < nck[0]; i++)
        {
            if (time >= times[i]&&pe<nck[1])
                pe++;
            else
            {
                time = times[i] + nck[2];
                pe = 1;
                result++;
            }
        }
        WriteLine(result);
    }
}