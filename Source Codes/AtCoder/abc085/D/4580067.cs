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
        var nh = Input.ar;
        var ab = Input.twodim(nh[0]);
        ab = ab.OrderByDescending(v => v[1]).ToArray();
        var max = ab.Max(ar => ar[0]);
        var res = 0;
        for(var i = 0; i < nh[0]; i++)
        {
            if (nh[1] == 0||max > ab[i][1])
                break;
            nh[1] = Max(nh[1] - ab[i][1], 0);
            res++;
        }
        WriteLine((nh[1] + max - 1) / max + res);
    }
}

public class Input
{
    public static string read => ReadLine();
    public  static int[] ar => Array.ConvertAll(read.Split(' '), int.Parse);
    public  static int num => ToInt32(read);
    public  static long[] arL => Array.ConvertAll(read.Split(' '), long.Parse);
    public  static long numL => ToInt64(read);
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}