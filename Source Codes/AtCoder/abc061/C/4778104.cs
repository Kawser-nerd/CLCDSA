using System;
using System.Collections.Generic;
using System.Linq;

public static partial class Program
{
    public static void Main()
    {
        var nk = CRL().SpTLongs();
        var n = nk[0];
        var k = nk[1];
        var array = new List<KeyValuePair<int, int>>();
        for (int i = 0; i < n; i++)
        {
            var ab = CRL().SpTInts();
            var a = ab[0];
            var b = ab[1];
            array.Add(new KeyValuePair<int, int>(a, b));
        }

        array = array.OrderBy(x => x.Key).ToList();
        for (int i = 0; i < n; i++)
        {
            k -= array[i].Value;
            if (k <= 0)
            {
                CWL(array[i].Key);
                return;
            }
        }
    }
}

public static partial class Program
{
    //????????
    private static int ToInt(this string str) => int.Parse(str);
    private static long ToLong(this string str) => long.Parse(str);
    private static int[] ToInt(this IEnumerable<string> strs) => strs.Select(x => x.ToInt()).ToArray();
    private static long[] ToLong(this IEnumerable<string> strs) => strs.Select(x => x.ToLong()).ToArray();
    public static int[] SpTInts(this string str, char opr = ' ') => str.Split(opr).ToInt();
    public static long[] SpTLongs(this string str, char opr = ' ') => str.Split(opr).ToLong();
    public static string CRL() => Console.ReadLine();
    public static void CWL(object obj) => Console.WriteLine(obj);
    public static int Diff(int a, int b) => Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    public static long Diff(long a, long b) => Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    public static int Sign(this int i) => Math.Sign(i);
    public static bool IsEven(this int i) => i % 2 == 0;
    public static int[] dx = new int[] { 0, -1, 0, 1 };
    public static int[] dy = new int[] { -1, 0, 1, 0 };
    public static long mod = 1000000007;
    public static string alphabet = "abcdefghijklmnopqrstuvwxyz";
    public static int ToInt(this char c) => c.ToString().ToInt();
    public static long ToLong(this char c) => c.ToString().ToLong();
    //????????
}