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
        var nx = Array.ConvertAll(ReadLine().Split(' '), long.Parse);
        WriteLine(dfs(nx[1], nx[0]));
    }
    private static long dfs(long x,long level)
    {
        if (level == 0) return ToInt64(x > 0);
        var bab = (long)Pow(2, level + 2) - 3;
        if (x < (bab + 1) / 2)
            return dfs(x-1, level - 1);  
        else if (x > (bab + 1) / 2)
            return (long)Pow(2, level) + dfs(x - (bab + 1) / 2, level - 1);
        else return (long)Pow(2, level);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}