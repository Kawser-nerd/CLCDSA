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
        var rck = Input.ar;
        var num = Input.num;
        var rc = Input.twodim(num);
        var ct = new[] { new int[rck[0]], new int[rck[1]] };
        for (var i = 0; i < 2; i++)
            for (var j = 0; j < num; j++)
                ct[i][rc[j][i] - 1]++;
        var can = new[] { new int[num + 1], new int[num + 1] };
        for(var j=0;j<2;j++)
        for (var i = 0; i < rck[j]; i++)
            can[j][ct[j][i]]++;
        var res = 0L;
        for (var j = 0; j <= rck[2]; j++)
            res += can[0][j] * can[1][rck[2] - j];
        for(var i = 0; i < num; i++)
        {
            var calc = ct[0][rc[i][0] - 1] + ct[1][rc[i][1] - 1];
            if (calc == rck[2]) res--;
            else if (calc == rck[2] + 1) res++;
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
    public const double eps = 1e-11;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}