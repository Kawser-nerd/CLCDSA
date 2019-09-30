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
    static void Main(string[] args)
    {
        Solve();
        //WriteLine(Solve());
    }
    static int[] nm;
    static void Solve()
    {
        nm = Input.ar;
        var adj = Enumerable.Repeat(0, nm[0]).Select(v => new List<int>()).ToArray();
        for(var i=0;i<nm[1];i++)
        {
            var inp = Input.ar;
            adj[inp[0] - 1].Add(inp[1] - 1);
            adj[inp[1] - 1].Add(inp[0] - 1);
        }
        WriteLine(dfs(adj, 0, 0) ? "POSSIBLE" : "IMPOSSIBLE");
    }
    static bool dfs(List<int>[] adj,int index,int depth)
    {
        if (depth == 2)
            return index == nm[0] - 1;
        var r = false;
        foreach (var ad in adj[index])
            if (!r) r = dfs(adj, ad, depth + 1);
            else break;
        return r;
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
    public static int[][] ar2D(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] arL2D(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}