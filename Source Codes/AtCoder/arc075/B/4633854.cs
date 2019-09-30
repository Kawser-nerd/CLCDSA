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
        var nab = Input.ar;
        var h = Enumerable.Repeat(0, nab[0]).Select(v => Input.numL).ToArray();
        var left = 0;
        var right = (int)1e9;
        while (right - left > 1)
        {
            var mid = (right + left) / 2;
            var ct = 0L;
            for (var i = 0; i < nab[0]; i++)
            {
                var l = -1L;
                var r = h[i];
                while (r - l > 1)
                {
                    var m = (r + l) / 2;
                    var point = m * nab[1] + (mid - m) * nab[2];
                    if (point >= h[i]) r = m;
                    else l = m;
                }
                ct += r;
            }
            if (ct > mid) left = mid;
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
    public static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}