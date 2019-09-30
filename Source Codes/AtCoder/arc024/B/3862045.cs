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
        var color = new int[num];
        for (var i = 0; i < num; i++)
            color[i] = ToInt32(ReadLine());
        var ind = -1;
        for(var i = num - 1; i >= 0; i--)
        {
            if (i == 0) { WriteLine(-1); return; }
            var p = 1 - color[0];
            if (color[i] == p) { ind = i; break; }
        }
        var max = num-ind;
        var n = num-ind;
        for(var i = 1; i <= ind; i++)
        {
            if (color[i] == color[i - 1]) n++;
            else n = 1;
            max = Max(max, n);
        }
        WriteLine(Ceiling((double)max / 2));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}