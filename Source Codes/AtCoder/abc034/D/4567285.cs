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
        var wp = Enumerable.Repeat(0, nk[0]).Select(v => Input.ar).ToArray();
        var left = 0d;
        var right = 100d;
        for (var i = 0; i < 200; i++)
        {
            var mid = (right + left) / 2;
            var pri = wp.Select(ar => ar[0] * (ar[1] - mid)).OrderByDescending(v=>v).ToArray();
            var max = pri.Take(nk[1]).Sum();
            if (max >= 0) left = mid;
            else right = mid;
        }
        WriteLine(right);
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