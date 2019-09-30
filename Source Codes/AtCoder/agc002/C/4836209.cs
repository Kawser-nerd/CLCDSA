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
        var nl = Input.ar;
        var ar = Input.ar;
        var res = new int[nl[0] - 1];
        var f = -1;
        for (var i = 0; i < nl[0] - 1; i++)
            if (ar[i] + ar[i + 1] >= nl[1])
                f = i + 1;
        if (f == -1)
        {
            WriteLine("Impossible");
            return;
        }
        res[0] = f;
        var q = f-1;
        var index = 1;
        while (q > 0)
        {
            res[index] = q;
            index++;
            q--;
        }
        q = f + 1;
        while (q < nl[0])
        {
            res[index] = q;
            index++;
            q++;
        }
        WriteLine("Possible");
        WriteLine(string.Join("\n", res.Reverse()));
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
    public static int[][] ar2D(int num)
        => Enumerable.Repeat(0, num).Select(v => ar).ToArray();
    public static long[][] arL2D(int num)
        => Enumerable.Repeat(0, num).Select(v => arL).ToArray();
    public const long Inf = (long)1e18;
    public const double eps = 1e-6;
    public  const string Alfa = "abcdefghijklmnopqrstuvwxyz";
    public  const int MOD = 1000000007;
}