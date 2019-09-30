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
        var nm = Input.ar;
        var xyz = Input.twodimL(nm[0]);
        var res = 0L;
        for(var i = 0; i < 8; i++)
        {
            var ar = new[] { -1, -1, -1 };
            for (var j = 0; j < 3; j++)
                if ((1 & i >> j) == 1)
                    ar[j] = 1;
            var so = xyz.OrderByDescending(v => v[0] * ar[0] + v[1] * ar[1] + v[2] * ar[2]).Take(nm[1]).ToArray();
            var sum = 0L;
            for (var j = 0; j < 3; j++)
                sum += Abs(so.Sum(v => v[j]));
            res = Max(res, sum);
        }
        WriteLine(res);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  
static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}