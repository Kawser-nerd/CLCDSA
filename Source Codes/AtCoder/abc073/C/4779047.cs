using System;
using System.Collections.Generic;
using System.Linq;

public static partial class Program
{
    public static void Main()
    {
        var n = CRL().ToInt();
        var count = 0;
        var list = new List<long>();
        for (int i = 0; i < n; i++)
        {
            list.Add(CRL().ToInt());
        }
        list.Sort();
        var does = 1;
        var index = 0;
        while (index < n)
        {
            var target = list[index];
            var buf = 0;
            while (index < n && list[index] == target)
            {
                buf++;
                index++;
            }

            if (buf.IsEven() == false)
            {
                count++;
            }
        }
        CWL(count);
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
    //????????
}