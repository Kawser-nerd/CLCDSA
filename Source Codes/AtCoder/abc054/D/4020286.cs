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
        var nm = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var abc = new int[nm[0]][];
        for (var i = 0; i < nm[0]; i++)
            abc[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var dp = new long[nm[0]+1, 401, 401];
        for(var i = 0; i <= nm[0]; i++)
        {
            for(var j = 0; j < 401; j++)
            {
                for (var h = 0; h < 401; h++)
                    dp[i, j, h] = int.MaxValue;
            }
        }
        dp[0, 0, 0] = 0;
        for(var i = 0; i < nm[0]; i++)
        {
            for(var j = 0; j < 401; j++)
            {
                for(var h = 0; h < 401; h++)
                {
                    dp[i + 1, j, h] = Min(dp[i, j, h], dp[i + 1, j, h]);
                    if(j+abc[i][0]<=400&&h+abc[i][1]<=400)
                    dp[i + 1, j + abc[i][0], h + abc[i][1]] =
                        Min(dp[i, j + abc[i][0], h+abc[i][1]], abc[i][2] + dp[i, j, h]);

                }
            }
        }
        long res = int.MaxValue;
        for(var i = 0; i < 401; i++)
        {
            for (var j = 0; j < 401; j++)
            {
                if (i == 0 && j == 0) continue;
                if(i*nm[2]==j*nm[1])
                res = Min(res, dp[nm[0], i, j]);
            }
        }
        WriteLine(res==int.MaxValue?-1:res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}