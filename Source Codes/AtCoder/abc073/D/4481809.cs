using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    private static long min = int.MaxValue;
    static void Main(string[] args)
    {
        var nmr = Input.ar;
        var ar = Input.ar;
        var ad = new List<int>[nmr[0]];
        var dis = new long[nmr[0], nmr[0]];
        for (var i = 0; i < nmr[0]; i++)
            ad[i] = new List<int>();
        for(var i = 0; i < nmr[1]; i++)
        {
            var inp = Input.ar;
            for(var j = 0; j < 2; j++)
            {
                ad[inp[j] - 1].Add(inp[(j + 1) % 2] - 1);
                dis[inp[j] - 1, inp[(j + 1) % 2] - 1] = inp[2];
            }
        }
        for (var i = 0; i < nmr[0]; i++)
            for (var j = 0; j < nmr[0]; j++)
                if (i != j && dis[i, j] == 0)
                    dis[i, j] = int.MaxValue;
        for (var k = 0; k < nmr[0]; k++)
            for (var i = 0; i < nmr[0]; i++)
                for (var j = 0; j < nmr[0]; j++)
                    dis[i, j] = Min(dis[i, j], dis[i, k] + dis[k, j]);
        for (var i = 0; i < nmr[2]; i++)
            dfs(ar, new bool[nmr[2]], i, 0, dis);
        WriteLine(min);
    }
    private static void dfs(int[] ar,bool[] th,int index,long sum,long[,] dis)
    {
        th[index] = true;
        if (th.Count(c => c) == ar.Length)
        {
            min = Min(min, sum);
            th[index] = false;
            return;
        }
        for (var i = 0; i < ar.Length; i++)
            if (!th[i])
                dfs(ar, th, i, sum + dis[ar[index]-1, ar[i]-1], dis);
        th[index] = false;
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