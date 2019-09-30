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
        var nk = Input.ar;
        var que = Enumerable.Repeat(0, nk[0]).Select(v => Input.ar).ToArray();
        WriteLine(dfs(que, 0, 0) ? "Found" : "Nothing");
    }
    private static bool dfs(int[][] que,int depth,int calc)
    {
        if (depth == que.Length)
            return calc == 0;
        var bo = false;
        for (var i = 0; i < que[0].Length; i++)
            if (!bo)
                bo = dfs(que, depth + 1, calc ^ que[depth][i]);
            else break;
        return bo;
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