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
        var nm = Input.ar;
        var adj = new List<int>[nm[0]];
        for (var i = 0; i < nm[0]; i++)
            adj[i] = new List<int>();
        var dp = new long[nm[0], nm[0]];
        var weit = new List<int>();
        for (var i = 0; i < nm[1]; i++)
        {
            var inp = Input.ar;
            if (inp[0] != 1 && inp[1] != 1)
                for (var j = 0; j < 2; j++)
                {
                    adj[inp[j]-1].Add(inp[(j + 1) % 2] - 1);
                    dp[inp[j] - 1, inp[(j + 1) % 2] - 1] = inp[2];
                }
            else
            {
                var max = Max(inp[0] - 1, inp[1] - 1);
                adj[0].Add(max);
                weit.Add(inp[2]); 
            }
        }
        for (var i = 1; i < nm[0]; i++)
            for (var j = 1; j < nm[0]; j++)
                if (i != j && dp[i, j] == 0)
                    dp[i, j] = int.MaxValue;
        for (var k = 1; k < nm[0]; k++)
            for (var i = 1; i < nm[0]; i++)
                for (var j = 1; j < nm[0]; j++)
                    dp[i, j] = Min(dp[i, j], dp[i, k] + dp[k, j]);
        var res = (long)int.MaxValue;
        for (var i = 0; i < adj[0].Count(); i++)
            for (var j = 0; j < adj[0].Count(); j++)
                if (i != j)
                    res = Min(res, Min(weit[i] + dp[adj[0][i], adj[0][j]] + weit[j],int.MaxValue));
        WriteLine(res==int.MaxValue?"-1":res.ToString());
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