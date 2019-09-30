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
    static int[] hw;
    private static long[,] memo;
    static int[] gH = new[] { 0, 0, 1, -1 };
    static int[] gW = new[] { 1, -1, 0, 0 };
    static void Main(string[] args)
    {
        hw = Input.ar;
        var gred = Input.twodim(hw[0]);
        memo = new long[hw[0], hw[1]];
        var th = new bool[hw[0], hw[1]];
        var res = 0L;
        for (var i = 0; i < hw[0]; i++)
            for (var j = 0; j < hw[1]; j++)
                res = (res+dfs(gred, i, j, th)) % Input.MOD;
        WriteLine(res);
    }
    private static long dfs(int[][] gred,int h,int w,bool[,] th)
    {
        if (th[h, w])
            return memo[h, w];
        th[h, w] = true;
        var val = 1L;
        for(var i = 0; i < 4; i++)
        {
            var nh = h + gH[i];
            var nw = w + gW[i];
            if (Search.IsInside(nh, nw, hw) && gred[h][w] > gred[nh][nw])
                val = (val + dfs(gred, nh, nw, th)) % Input.MOD;
        }
        return memo[h, w] = val;
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
        if (num % 2 == 0 || num == 1) return false;
        for (var i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
}