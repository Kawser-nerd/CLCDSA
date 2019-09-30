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
        var isEnd = false;
        GetB(ts, 0, nk[1], new int[5], ref isEnd);
        if (!isEnd)  WriteLine("Nothing"); 
    }

    private static void GetB(int[][] ts,int i,int k,int[] select,ref bool isEnd)
    {
        if (isEnd) return;
        for(var j = 0; j < k; j++)
        {
            if (i != ts.Length-1)
            {
                select[i] = j;
                GetB(ts, i + 1, k, select,ref isEnd);
            }
            else
            {
                var n = ts[ts.Length-1][j];
                for(var h = 0; h < ts.Length-1; h++)
                {
                    n ^= ts[h][select[h]];
                }
                if (n == 0) { WriteLine("Found");isEnd = true;return; }
            }
        }
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}