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
        var num = Input.numL;
        var list = new List<long>();
        for (var i = 0; i < 15; i++)
            for (var j = 1; j < 150; j++)
                list.Add((j + 1) * (long)Pow(10, i) - 1);
        list = list.Distinct().OrderBy(v => v).ToList();
        for (var i = 0; i < list.Count; i++)
        {
            var cc = true;
            for (var j = i + 1; j < list.Count; j++)
                if (cc)
                    cc = calc(list[i]) <= calc(list[j]);
                else break;
            if (cc)
            {
                WriteLine(list[i]);
                num--;
            }
            if (num == 0) return;
        }
    }
    static double calc(long num)
    {
        double d = num;
        var dig = 0;
        var s = num.ToString();
        for (var i = 0; i < s.Length; i++)
            dig += s[i] - '0';
        return d / dig;
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