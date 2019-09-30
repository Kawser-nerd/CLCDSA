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
    public static int[] ToIA(this string str, char opr = ' ') => str.Split(opr).ToInt();
    public static long[] ToLA(this string str, char opr = ' ') => str.Split(opr).ToLong();
    public static string CRL() => Console.ReadLine();
    public static void CWL(object obj) => Console.WriteLine(obj);
    public static int Diff(int a, int b) => (int)Diff(a, (long)b);
    public static long Diff(long a, long b) => Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    public static int Sign(this int i) => Math.Sign(i);
    public static bool IsEven(this int i) => i % 2 == 0;
    public static int[] dx = new int[] { 0, -1, 0, 1 };
    public static int[] dy = new int[] { -1, 0, 1, 0 };
    public static int[] ToFlat(this int[] array) => array.Cast<long>().ToArray().ToFlat().Cast<int>().ToArray();
    public static long[] ToFlat(this long[] array)                  //???
    {
        var min = array.Min();
        return array.Select(x => x - min).ToArray();
    }
    public static int Gcd(int a, int b) => (int)Gcd(a, (long)b);
    public static long Gcd(long a, long b)
    {
        if (b == 0)
        {
            return a;
        }

        return Gcd(b, a % b);
    }                       //?????
    public static int Lcm(int a, int b) => (int)Lcm(a, (long)b);
    public static long Lcm(long a, long b) => a / Gcd(a, b) * b;    //?????
    //????????
}

public static partial class Program
{
    static void Main()
    {
        var ny = CRL().ToIA();
        var n = ny[0];
        var y = ny[1];

        for (int ten = 0; ten <= n; ten++)
        {
            for (int five = 0; five <= n - ten; five++)
            {
                var one = n - ten - five;
                if (ten * 10000 + five * 5000 + one * 1000 == y)
                {
                    CWL($"{ten} {five} {one}");
                    return;
                }
            }
        }

        CWL("-1 -1 -1");
    }
}