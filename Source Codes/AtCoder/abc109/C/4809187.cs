using System;
using System.Collections.Generic;
using System.Linq;

public static partial class Program
{
    public static void Main()
    {
        var nx = CRL().ArrayLongs();
        var n = nx[0];
        var x = nx[1];
        var axis = CRL().ArrayLongs();
        for (int i = 0; i < n; i++)
        {
            axis[i] = Diff(x, axis[i]);
        }

        long gcd = axis[0];
        for (int i = 1; i < n; i++)
        {
            gcd = GCD(axis[i], gcd);
        }

        CWL(gcd);
    }
}

public static partial class Program
{
    //????????
    private static long ToInt(this string str) => long.Parse(str);
    private static long[] ToInt(this IEnumerable<string> strs) => strs.Select(x => x.ToInt()).ToArray();
    public static long[] ArrayLongs(this string str, char opr = ' ') => str.Split(opr).ToInt();
    public static string CRL() => Console.ReadLine();
    public static void CWL(object obj) => Console.WriteLine(obj);
    public static long Diff(long a, long b) => Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    public static long Sign(this long i) => Math.Sign(i);
    public static bool IsEven(this long i) => i % 2 == 0;
    public static bool IsEven(this int i) => i % 2 == 0;
    public static long[] dx = new long[] { 0, -1, 0, 1 };
    public static long[] dy = new long[] { -1, 0, 1, 0 };
    public static long mod = 1000000007;
    public static string alphabet = "abcdefghijklmnopqrstuvwxyz";
    public static long ToLong(this char c) => c.ToString().ToInt();
    public static long[] Sort(this long[] array)
    {
        var list = array.ToList();
        list.Sort();
        return list.ToArray();
    }
    public static long GCD(long a, long b) => b == 0 ? a : GCD(b, a % b);
    public static long LCM(long a, long b) => a * b / GCD(a, b);
    //????????
}