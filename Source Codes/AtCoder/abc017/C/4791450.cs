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
        var nm = Input.ar;
        var lrs = Input.twodim(nm[0]);
        var imos = new int[nm[1] + 1];
        for(var i=0;i<nm[0];i++)
        {
            imos[lrs[i][0] - 1] += lrs[i][2];
            imos[lrs[i][1]] -= lrs[i][2];
        }
        for (var i = 1; i <= nm[1]; i++)
            imos[i] += imos[i - 1];
        imos[nm[1]]=int.MaxValue;
        WriteLine(lrs.Sum(ar => ar[2]) - imos.Min());
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