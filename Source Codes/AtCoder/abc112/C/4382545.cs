using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var xyh = new int[num][];
        for (var i = 0; i < num; i++)
            xyh[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        for (var i=0;i<101;i++)
            for(var j = 0; j < 101; j++)
            {
                var minh = int.MaxValue;
                for(var k = 0; k < num; k++)
                    minh = Min(minh, calc(i, j, xyh[k]));
                var isTh = true;
                for (var k = 0; k < num; k++)
                    if (isTh)
                        isTh = xyh[k][2] == Max(0, minh - Abs(i - xyh[k][0]) - Abs(j - xyh[k][1]));
                    else break;
                if (isTh)
                {
                    WriteLine($"{i} {j} {minh}");
                    return;
                }
            }
    }
    private static int calc(int i,int j,int[] vex)
    {
        return Abs(i - vex[0]) + Abs(j - vex[1]) + vex[2];
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}