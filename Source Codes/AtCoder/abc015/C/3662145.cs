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
        var nk = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ts = new int[nk[0]][];
        for (var i = 0; i < nk[0]; i++)
            ts[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        WriteLine(GetB(ts, 0, nk[1], 0) ? "Found" : "Nothing");
    }

    private static bool GetB(int[][] ts, int i, int k, int val)
    {
        if (i == ts.Length) return val == 0;
        for (var j = 0; j < k; j++)
        {
            if (GetB(ts, i+1, k, val ^ ts[i][j])) return true;
        }
        return false;
    }
}