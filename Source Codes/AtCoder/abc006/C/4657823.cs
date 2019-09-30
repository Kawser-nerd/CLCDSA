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

public static partial class Program
{
    static void Main()
    {
        var nm = CRL().SplToInt().ToArray();
        var n = nm[0];
        var m = nm[1];

        for (int c = 0; c <= n; c++)
        {
            var b = m - n * 2 - c * 2;
            var a = c + n * 3 - m;
            if (a.Sign() < 0 || b.Sign() < 0)
            {
                continue;
            }

            CWL($"{a} {b} {c}");
            return;
        }

        CWL("-1 -1 -1");
    }
}