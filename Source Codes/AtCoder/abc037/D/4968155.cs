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
        Solve();
        //WriteLine(Solve());
    }
    static long[,] memo;
    static bool[,] th;
    static int[] hw;
    static int[][] gred;
    static int[] gh = new[] { 0, 0, 1, -1 };
    static int[] gw = new[] { 1, -1, 0, 0 };
    static void Solve()
    {
        hw = Input.ar;
        gred = Input.ar2D(hw[0]);
        memo = new long[hw[0], hw[1]];
        th = new bool[hw[0], hw[1]];
        for (var i = 0; i < hw[0]; i++)
            for (var j = 0; j < hw[1]; j++)
                if (!th[i, j])
                    dfs(i, j);
        var res = 0L;
        for (var i = 0; i < hw[0]; i++)
            for (var j = 0; j < hw[1]; j++)
                res = (res+memo[i, j])%Input.MOD;
        WriteLine(res);
    }
    static long dfs(int h,int w)
    {
        if (th[h, w]) return memo[h, w];
        th[h, w] = true;
        var calc = 1L;
        for(var i = 0; i < 4; i++)
        {
            var hh = h + gh[i];
            var ww = w + gw[i];
            if (!Search.IsInside(hh, ww, hw)||gred[h][w]<=gred[hh][ww]) continue;
            calc += dfs(hh, ww);
            calc %= Input.MOD;
        }
        return memo[h, w] = calc;
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

public class Search
{
    public static int UpperBound<T>(T[] array,T value)
        where T:IComparable<T>
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].CompareTo(value) == 1) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static int LowerBound<T>(T[] array,T value)
        where T : IComparable<T>
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].CompareTo(value) != -1) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static T Max<T>(params T[] array)
        => array.Max();
    public static T Min<T>(params T[] array)
        => array.Min();
    public static bool IsInside(int h, int w, int[] hw)
        => 0 <= h && h < hw[0] && 0 <= w && w < hw[1];
    public static bool IsPrime(long num)
    {
        if (num % 2 == 0 || num == 1) return num == 2;
        for (var i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
}