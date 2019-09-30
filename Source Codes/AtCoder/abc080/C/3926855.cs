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
        var open = new int[num][];
        for (var i = 0; i < num; i++)
            open[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var be = new int[num][];
        for (var i = 0; i < num; i++)
            be[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);

        var res = long.MinValue;
        for(var i = 1; i < Pow(2,10); i++)
        {
            var r = 0L;
            var wo = new int[10];
            for(var j = 0; j < 10; j++)
            {
                if (((i >> j) & 1) == 1)
                {
                    wo[j] = 1;
                }
            }

            var count = new int[num];
            for(var j = 0; j < num; j++)
            {
                for(var h = 0; h < 10; h++)
                {
                    if (open[j][h] == 1 && wo[h] == 1)
                        count[j]++;
                }
            }
            for (var j = 0; j < num; j++)
                r += be[j][count[j]];
            res = Max(r, res);
        }
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}