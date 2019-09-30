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
        var ar = new[] { Input.ar, Input.ar };
        var res = new[] { 0L, 0L };
        for (var j = 0; j < 2; j++)
            for (var i = 0; i < nm[j]; i++)
                res[j] = (res[j] + ((long)(i + 1) * 2 - 1 - nm[j]) * ar[j][i]%Input.MOD) % Input.MOD;
        WriteLine(res[0] * res[1] % Input.MOD);
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
    public static Tuple<int, int, long> MakeEdge(int num1, int num2, long weight=Inf)
        => new Tuple<int, int, long>(num1, num2, weight);
    public const long Inf = (long)1e18;
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}