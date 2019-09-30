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
        var xy = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var num = ToInt32(ReadLine());
        var xys = new int[num][];
        for (var i = 0; i < num; i++)
            xys[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var min = 1000000d;
        for (var i = 0; i < num; i++)
        {
            var ind = (i + 1) % num;
            double d1 = xys[ind][0] - xys[i][0];
            double d2 = xys[ind][1] - xys[i][1];
            var d = Abs(d2 * xy[0] - d1 * xy[1] + xys[i][1] * xys[ind][0] - xys[ind][1] * xys[i][0])
                / Sqrt(d1 * d1 + d2 * d2);
            min = Min(min, d);
        }
        WriteLine(min);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}