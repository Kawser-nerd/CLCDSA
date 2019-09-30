using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var nab = Input.ar;
        const int LI = 401;
        var abc = new int[nab[0]][];
        for (var i = 0; i < nab[0]; i++)
            abc[i] = Input.ar;
        var dp = new int[nab[0]+1, LI, LI];
        for (var i = 0; i <= nab[0]; i++)
            for (var j = 0; j < LI; j++)
                for (var h = 0; h < LI; h++)
                    dp[i, j, h] = int.MaxValue;
        dp[0, 0, 0] = 0;
        for(var i = 1; i <= nab[0]; i++)
        {
            for (var j = 0; j < LI; j++)
            {
                for (var h = 0; h < LI; h++)
                {
                    dp[i, j, h] = Min(dp[i, j, h], dp[i - 1, j, h]);
                    if (j - abc[i - 1][0] < 0 || h - abc[i - 1][1] < 0)
                        continue;
                    if (dp[i - 1, j - abc[i - 1][0], h - abc[i - 1][1]] != int.MaxValue)
                        dp[i, j, h] = Min(dp[i, j, h], dp[i - 1, j - abc[i - 1][0], h - abc[i - 1][1]] + abc[i - 1][2]); 
                }
            }
        }
        var min = int.MaxValue;
        for(var i=1;i<LI;i++)
            for(var j = 1; j < LI; j++)
                if (i * nab[2] == j * nab[1])
                    min = Min(min, dp[nab[0], i, j]);
        WriteLine(min == int.MaxValue ? -1 : min);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}