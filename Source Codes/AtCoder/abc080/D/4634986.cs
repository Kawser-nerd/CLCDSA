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
        var nc = Input.ar;
        var stc = Input.twodim(nc[0]);
        const int NUM = 200002;
        var res = new int[NUM];
        for (var i = 0; i < nc[1]; i++)
        {
            var imos = new int[NUM];
            for(var j = 0; j < nc[0]; j++)
            {
                if (stc[j][2]-1 != i) continue;
                imos[2 * stc[j][0] - 1]++;
                imos[2 * stc[j][1]]--;
            }
            for (var j = 1; j < NUM; j++)
                imos[j] += imos[j - 1];
            for (var j = 0; j < NUM; j++)
                if (imos[j] > 0) res[j]++;
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
    public static int[][] twodim(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] twodimL(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}