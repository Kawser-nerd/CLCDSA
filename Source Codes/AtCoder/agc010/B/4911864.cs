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
        //Solve();
        WriteLine(Solve());
    }
    static string Solve()
    {
        var num = Input.numL;
        var ar = Input.arL;
        var sum = ar.Sum();
        if (sum % (num * (num + 1) / 2) != 0)
            return "NO";
        sum /= num * (num + 1) / 2;
        for(var i = 0; i < num; i++)
        {
            var dif = ar[(i + 1) % num] - ar[i];
            dif -= sum;
            if (dif > 0 || dif % num != 0) return "NO";
        }
        return "YES";
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