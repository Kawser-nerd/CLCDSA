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
        var c = ToInt32(ReadLine());
        var th = new int[c][];
        for (var i = 0; i < c; i++)
            th[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var isSe = new bool[c, 3];
        var result = new int[3];
        for (var j = 0; j < 3; j++)
        {
            var m = 0;
            for (var i = 0; i < c; i++)
            {
                var max = 0;
                var maxi = -1;
                for(var h=0;h<3;h++)
                    if (!isSe[i,h]&&max < th[i][h])
                    {
                        max = th[i][h];
                        maxi = h;
                    }
                isSe[i, maxi] = true;
                m = Max(m, max);
            }
            result[j] = m;
        }
        WriteLine(result[0] * result[1] * result[2]);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}