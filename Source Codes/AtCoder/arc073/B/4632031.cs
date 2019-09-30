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
        var nw = Input.ar;
        var wv = Input.twodim(nw[0]);
        var dic = new Dictionary<int, List<int>>();
        for (var i = wv[0][0]; i <= wv[0][0]+3; i++)
            dic[i] = new List<int>();
        for (var i = 0; i < nw[0]; i++)
            dic[wv[i][0]].Add(wv[i][1]);
        var list = dic.Values.Select(ls => ls.OrderByDescending(c => c).ToList()).ToArray();
        WriteLine(dfs(list,0, 0, wv[0][0], nw[1]));
    }
    private static long dfs(List<int>[] list, int index, long nowwei,long wei,long limit)
    {
        if (index > 3) return 0;
        var val = dfs(list, index + 1, nowwei, wei, limit);
        var v = 0L;
        var w = 0L;
        for (var i = 0; i < list[index].Count; i++)
        {
            v += list[index][i];
            w += index + wei;
            if (w + nowwei > limit) break;
            var p = dfs(list, index + 1, nowwei + w, wei, limit);
            val = Max(val, v + p);
        }
        
        return val;
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}