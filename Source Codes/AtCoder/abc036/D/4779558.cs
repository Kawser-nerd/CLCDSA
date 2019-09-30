using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using Debug;
//using static System.Globalization.CultureInfo;

class Program
{
    static long[,] memo;
    static bool[] th;
    static void Main(string[] args)
    {
        var num = Input.num;
        var adj = Enumerable.Repeat(0, num).Select(v => new List<int>()).ToArray();
        memo = new long[num, 2];
        th = new bool[num];
        for (var i = 0; i < num - 1; i++)
        {
            var inp = Input.ar;
            adj[inp[0] - 1].Add(inp[1] - 1);
            adj[inp[1] - 1].Add(inp[0] - 1);
        }
        dfs(adj, 0);
        WriteLine((memo[0, 0] + memo[0, 1]) % Input.MOD);
    }
    static void dfs(List<int>[] adj,int index)
    {
        th[index] = true;
        memo[index, 0] = 1;
        memo[index, 1] = 1;
        foreach (var ad in adj[index])
            if (!th[ad])
            {
                dfs(adj, ad);
                memo[index, 0] = (memo[ad, 0] + memo[ad, 1]) % Input.MOD * memo[index, 0] % Input.MOD;
                memo[index, 1] = memo[index, 1] * memo[ad, 0] % Input.MOD;
            }
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static char[][] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read.ToCharArray()).ToArray();
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}