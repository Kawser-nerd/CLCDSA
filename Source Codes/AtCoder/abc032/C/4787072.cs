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
        var nk = Input.ar;
        var ar = Enumerable.Repeat(0, nk[0]).Select(_ => Input.num).ToArray();
        if (ar.Contains(0))
        {
            WriteLine(nk[0]);
            return;
        }
        var left = 0;
        var right = 0;
        var val = 1L;
        var res = 0;
        while (right < nk[0] && left < nk[0])
        {
            if (val * ar[right] <= nk[1])
            {
                val *= ar[right];
                right++;
            }else if (right == left)
            {
                right++;
                left++;
            }
            else
            {
                val /= ar[left];
                left++;
            }
            res = Max(res, right - left);
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
    public static char[][] gred(int h) 
        => Enumerable.Repeat(0, h).Select(v => read.ToCharArray()).ToArray();
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}