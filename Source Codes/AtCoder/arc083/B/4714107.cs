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
        var ar = Input.twodimL(num);
        var dist = Enumerable.Repeat(0, num).Select(v => new long[num]).ToArray();
        for (var i = 0; i < num; i++)
            for (var j = 0; j < num; j++)
                dist[i][j] = ar[i][j];
        var bo = new bool[num, num];
        for (var k = 0; k < num; k++)
            for (var i = 0; i < num; i++)
                for (var j = 0; j < num; j++)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        WriteLine(-1);
                        return;
                    }
                    else if (i != k && j != k && dist[i][j] == dist[i][k] + dist[k][j])
                        bo[i, j] = true;
        var res = 0L;
        for (var i = 0; i < num; i++)
            for (var j = i + 1; j < num; j++)
                if (!bo[i, j]) res += dist[i][j]
   ;        WriteLine(res);
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