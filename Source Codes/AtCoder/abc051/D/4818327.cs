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
        var abc = new int[nm[1]][];
        var dist = new long[nm[0], nm[0]];
        for(var i = 0; i < nm[1]; i++)
        {
            abc[i] = Input.ar;
            dist[abc[i][0] - 1, abc[i][1] - 1] = abc[i][2];
            dist[abc[i][1] - 1, abc[i][0] - 1] = abc[i][2];
        }
        for (var i = 0; i < nm[0]; i++)
            for (var j = 0; j < nm[0]; j++)
                if (i != j && dist[i, j] == 0)
                    dist[i, j] = long.MaxValue / 2;
        for (var k = 0; k < nm[0]; k++)
            for (var i = 0; i < nm[0]; i++)
                for (var j = 0; j < nm[0]; j++)
                    dist[i, j] = Min(dist[i, j], dist[i, k] + dist[k, j]);
        var res = 0;
        foreach (var eg in abc)
            if (dist[eg[0]-1, eg[1]-1] != eg[2])
                res++;
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
    public const long Inf = (long)1e18/2;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}