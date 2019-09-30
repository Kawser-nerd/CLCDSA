using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using Pair = System.Tuple<int, int>;
using Edge = System.Tuple<int, int, long>;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var xy = Input.ar;
        var li = new[] { new List<int>(), new List<int>() };
        var s = str.Trim().Split('T');
        for (var i = 0; i < s.Length; i++)
            if (i % 2 == 0)
                li[0].Add(s[i].Length);
            else li[1].Add(s[i].Length);
        for(var i=0;i<2;i++)
        {
            var dp = Enumerable.Repeat(0, li[i].Count).Select(v => new HashSet<int>()).ToArray();
            if (i == 0) dp[0].Add(li[i][0]);
            else
            {
                if (li[1].Count == 0)
                {
                    WriteLine(xy[1] == 0 ? "Yes" : "No");
                    return;
                }
                dp[0].Add(li[i][0]);
                dp[0].Add(-li[i][0]);
            }
            for(var j=1;j<li[i].Count;j++)
                for(var h=-str.Length;h<=str.Length;h++)
                    if (dp[j-1].Contains(h))
                    {
                        if (-str.Length <= h - li[i][j])
                            dp[j].Add(h - li[i][j]);
                        if (str.Length >= h + li[i][j])
                            dp[j].Add(h + li[i][j]);
                    }
            if (!dp[li[i].Count-1].Contains(xy[i]))
            {
                WriteLine("No");
                return;
            }
        }
        WriteLine("Yes");
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static string[] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read).ToArray();
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}