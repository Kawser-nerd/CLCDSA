using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

public static partial class Program
{
    public static void Main()
    {
        var abcd = CRL().ToCharArray().Select(x => x.ToLong()).ToArray();
        var a = abcd[0];
        var b = abcd[1];
        var c = abcd[2];
        var d = abcd[3];
        var part = new int[2] { -1, +1 };
        var res = new string[2] { "-", "+" };

        for (int bIdx = 0; bIdx < 2; bIdx++)
        {
            for (int cIdx = 0; cIdx < 2; cIdx++)
            {
                for (int dIdx = 0; dIdx < 2; dIdx++)
                {
                    if (a + b * part[bIdx] + c * part[cIdx] + d * part[dIdx] == 7)
                    {
                        CWL(a + res[bIdx] + b + res[cIdx] + c + res[dIdx] + d + "=7");
                        return;
                    }
                }
            }
        }
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