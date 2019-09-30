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
        var num = Input.num;
        var ar = Input.ar;
        var ps = Enumerable.Range(0, num).Select(v => new[] { v, 0 }).ToArray();
        for (var i = 0; i < num; i++)
            ps[i][1] = ar[i];
        Array.Sort(ar);
        ps = ps.OrderBy(v => v[1]).ToArray();
        for (var i = 1; i <= num; i++)
            if (i <= num / 2) ps[i - 1][1] = ar[num / 2];
            else ps[i - 1][1] = ar[num / 2-1];
        WriteLine(string.Join("\n", ps.OrderBy(v => v[0]).Select(v => v[1])));
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
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}