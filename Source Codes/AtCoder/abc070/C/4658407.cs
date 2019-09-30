using System;
using System.Collections;
using System.Collections.Generic;
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
    public static int Gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }

        return Gcd(b, a % b);
    }
    public static long Gcd(long a, long b)
    {
        if (b == 0)
        {
            return a;
        }

        return Gcd(b, a % b);
    }
    public static int Lcm(int a, int b)
    {
        var g = Gcd(a, b);
        return a / g * b;
    }
    public static long Lcm(long a, long b)
    {
        var g = Gcd(a, b);
        return a / g * b;
    }
    //????????
}

public static partial class Program
{
    static void Main()
    {
        var n = CRL().ToInt();
        var times = new List<long>();
        long ans = 1;
        for (int i = 0; i < n; i++)
        {
            var input = CRL().ToLong();
            ans = Lcm(ans, input);
        }

        CWL(ans);
    }
}