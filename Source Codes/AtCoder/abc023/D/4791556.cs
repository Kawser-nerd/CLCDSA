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
        var num = Input.num;
        var hs = Input.twodim(num);
        var left = 0L;
        var right = (long)1e15;
        while (right - left > 1)
        {
            var mid = (right + left) / 2;
            var res = new int[num];
            var pp = true;
            for (var i = 0; i < num; i++)
            {
                if (mid < hs[i][0])
                {
                    pp = false;
                    break;
                }
                var calc = (mid - hs[i][0]) / hs[i][1];
                res[Min(num - 1, calc)]++;
            }
            var sum = 0L;
            for (var i = 0; i < num; i++)
                if (pp)
                {
                    sum += res[i];
                    pp = sum <= i + 1;
                }
                else break;
            if (!pp) left = mid;
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
    public static char[][] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read.ToCharArray()).ToArray();
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18/2;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}