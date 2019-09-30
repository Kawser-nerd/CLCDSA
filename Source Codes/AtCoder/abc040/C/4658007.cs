using System;
using System.Linq;

public static partial class Program
{
    //????????
    public static int ToInt(this string str) => int.Parse(str);
    public static long ToLong(this string str) => long.Parse(str);
    public static int[] ToInt(this string[] strs) => strs.Select(x => x.ToInt()).ToArray();
    public static long[] ToLong(this string[] strs) => strs.Select(x => x.ToLong()).ToArray();
    public static int[] SplToInt(this string str, char opr = ' ') => str.Split(opr).ToInt();
    public static long[] SplToLong(this string str, char opr = ' ') => str.Split(opr).ToLong();
    public static string CRL() => Console.ReadLine();
    public static void CWL(object obj) => Console.WriteLine(obj);
    public static int Diff(int a, int b) => Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    public static long Diff(long a, long b) => Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    public static int Sign(this int i) => Math.Sign(i);
    public static bool IsEven(this int i) => i % 2 == 0;
    public static int[] dx = new int[] { 0, -1, 0, 1 };
    public static int[] dy = new int[] { -1, 0, 1, 0 };
    public static int[] ToFlat(this int[] array)
    {
        var min = array.Min();
        return array.Select(x => x - min).ToArray();
    }
    public static long[] ToFlat(this long[] array)
    {
        var min = array.Min();
        return array.Select(x => x - min).ToArray();
    }
    //????????
}

/*
 * https://twitter.com/shibh308/status/1109054644246896640
 */

public static partial class Program
{
    static void Main()
    {
        var n = CRL().ToInt();
        var axis = CRL().SplToInt();
        var dp = new int[n];
        dp[0] = 0;
        dp[1] = Diff(axis[0], axis[1]);
        for (int i = 2; i < n; i++)
        {
            var two = Diff(axis[i - 2], axis[i]);
            var one = Diff(axis[i - 1], axis[i]);
            dp[i] = Math.Min(dp[i - 2] + two, dp[i - 1] + one);
        }

        CWL(dp[n - 1]);
    }
}