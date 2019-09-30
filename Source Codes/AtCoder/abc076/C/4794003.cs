using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

public static partial class Program
{
    public static void Main()
    {
        var s = CRL();
        var t = CRL();

        const string unres = "UNRESTORABLE";

        if (s.Length < t.Length)
        {
            CWL(unres);
            return;
        }

        for (int sIdx = s.Length - t.Length; sIdx >= 0; sIdx--)
        {
            var sb = new StringBuilder(s);
            var conf = false;
            for (int tIdx = 0; tIdx < t.Length; tIdx++)
            {
                if (s[sIdx + tIdx] == '?')
                {
                    sb[sIdx + tIdx] = t[tIdx];
                    continue;
                }

                if (s[sIdx + tIdx] != t[tIdx])
                {
                    conf = true;
                    break;
                }
            }

            if (conf)
            {
                continue;
            }

            CWL(sb.ToString().Replace("?", "a"));
            return;
        }

        CWL(unres);
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