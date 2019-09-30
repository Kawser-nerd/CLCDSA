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
        var nc = Input.ar;
        const int NUM = 2 * (int)1e5 + 2;
        var stc = Input.twodim(nc[0]);
        var res = new int[NUM];
        for(var i = 1; i <= nc[1]; i++)
        {
            var imos = new int[NUM];
            for(var j=0;j<nc[0];j++)
                if(stc[j][2]==i)
                {
                    imos[2 * stc[j][0] - 1]++;
                    imos[2 * stc[j][1] + 1]--;
                }
            for (var j = 1; j <NUM; j++)
                imos[j] += imos[j - 1];
            for (var j = 0; j <NUM; j++)
                if (imos[j] == 1)
                    res[j]++;
        }
        WriteLine(res.Max());
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