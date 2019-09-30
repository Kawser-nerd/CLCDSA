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
        var hw = Input.arL;
        var res = long.MaxValue;
        for (var k = 0; k < 2; k++)
            for (var i = 1; i < hw[k]; i++)
            {
                var ar = new[] { i * hw[1 - k], (hw[k] - i + 1) / 2 * hw[1 - k], (hw[k] - i) / 2 * hw[1 - k] };
                res = Min(res, ar.Max() - ar.Min());
                ar[1] = (hw[1 - k] + 1) / 2 * (hw[k] - i);
                ar[2] = hw[1 - k] / 2 * (hw[k] - i);
                res = Min(res, ar.Max() - ar.Min());
            }
        WriteLine(res);
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