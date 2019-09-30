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
        var num = Input.num;
        var res = (int)1e5;
        for (var i = 0; i <= num; i++)
        {
            var re = num - i;
            var ct = 0;
            var ct1 = i / 6;
            while (ct1 > 5) {
                ct += ct1 % 6;
                ct1 /= 6;
            }
            ct += i % 6 + ct1;
            var ct2 = re / 9;
            while(ct2>8)
            {
                ct += ct2 % 9;
                ct2 /= 9;
            }
            ct += re % 9 + ct2;
            res = Min(res, ct);
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