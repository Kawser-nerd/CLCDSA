using System;
using System.Collections.Generic;
using System.Linq;

public static partial class Program
{
    public static void Main()
    {
        var nk = CRL().ArrayLongs();
        var n = nk[0];
        var k = nk[1];
        var array = new List<KeyValuePair<long, long>>();
        for (int i = 0; i < n; i++)
        {
            var ab = CRL().ArrayLongs();
            var a = ab[0];
            var b = ab[1];
            array.Add(new KeyValuePair<long, long>(a, b));
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
    private static long ToLong(this string str) => long.Parse(str);
    private static long[] ToLong(this IEnumerable<string> strs) => strs.Select(x => x.ToLong()).ToArray();
    public static long[] ArrayLongs(this string str, char opr = ' ') => str.Split(opr).ToLong();
    public static string CRL() => Console.ReadLine();
    public static void CWL(object obj) => Console.WriteLine(obj);
    public static long Diff(long a, long b) => Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    public static long Sign(this long i) => Math.Sign(i);
    public static bool IsEven(this long i) => i % 2 == 0;
    public static long[] dx = new long[] { 0, -1, 0, 1 };
    public static long[] dy = new long[] { -1, 0, 1, 0 };
    public static long mod = 1000000007;
    public static string alphabet = "abcdefghijklmnopqrstuvwxyz";
    public static long ToLong(this char c) => c.ToString().ToLong();
    //????????
}