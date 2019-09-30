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
        var nmr = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var r = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var dp = new long[nmr[0], nmr[0]];
        for(var i = 0; i < nmr[1]; i++)
        {
            var input = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            dp[input[0] - 1, input[1] - 1] = input[2];
            dp[input[1] - 1, input[0] - 1] = input[2];
        }
        for (var i = 0; i < nmr[0]; i++)
            for (var j = 0; j < nmr[0]; j++)
                if (i != j && dp[i, j] == 0)
                    dp[i, j] = int.MaxValue;
        for (var k = 0; k < nmr[0]; k++)
            for (var i = 0; i < nmr[0]; i++)
                for (var j = 0; j < nmr[0]; j++)
                    dp[i, j] = Min(dp[i, j], dp[i, k] + dp[k, j]);
        var min = long.MaxValue;
        for (var i = 0; i < r.Length; i++)
            min = Min(min, dfs(dp, r, new HashSet<int>(), i));
        WriteLine(min);
    }
    private static long dfs(long[,] fromto, int[] rs, HashSet<int> set, int index)
    {
        set.Add(rs[index]);
        if (set.Count == rs.Length)
        {
            set.Remove(rs[index]);
            return 0;
        }
        var min = long.MaxValue;
        for (var i = 0; i < rs.Length; i++)
        {
            if (!set.Contains(rs[i]))
                min = Min(min, dfs(fromto, rs, set, i) + fromto[rs[index] - 1, rs[i] - 1]);
        }
        set.Remove(rs[index]);
        return min;
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}