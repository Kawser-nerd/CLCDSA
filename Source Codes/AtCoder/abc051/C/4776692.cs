using System;
using System.Collections.Generic;
using System.Linq;

public static partial class Program
{
    public static void Main()
    {
        var sstt = CRL().SpTInts();
        var s = new int[2] {sstt[0], sstt[1]};
        var t = new int[2] {sstt[2], sstt[3]};

        var xd = Diff(s[0], t[0]);
        var yd = Diff(s[1], t[1]);
        for (int i = 0; i < yd; i++)
        {
            Console.Write("U");
        }

        for (int i = 0; i < xd; i++)
        {
            Console.Write("R");
        }

        for (int i = 0; i < yd; i++)
        {
            Console.Write("D");
        }

        for (int i = 0; i < xd; i++)
        {
            Console.Write("L");
        }

        Console.Write("L");
        for (int i = 0; i < yd + 1; i++)
        {
            Console.Write("U");
        }

        for (int i = 0; i < xd + 1; i++)
        {
            Console.Write("R");
        }
        Console.Write("D");
        Console.Write("R");
        for (int i = 0; i < yd + 1; i++)
        {
            Console.Write("D");
        }

        for (int i = 0; i < xd + 1; i++)
        {
            Console.Write("L");
        }
        Console.WriteLine("U");
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
    public static string alphabet = "abcdefghijklmnopqrstuvwxyz";
    public static int ToInt(this char c) => c.ToString().ToInt();
    public static long ToLong(this char c) => c.ToString().ToLong();
    //????????
}