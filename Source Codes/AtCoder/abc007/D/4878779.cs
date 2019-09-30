using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

class Program
{
    static long A;
    static long B;

    public static void Main(string[] args)
    {
        A = Input.NextLong();
        B = Input.NextLong();

        var a = CountAll(A);
        var b = CountAll(B);

        var s = (B - b) - (A - a);
        var sa = A.ToString();
        if (sa.Contains('4') || sa.Contains('9'))
            s += 1;

        Console.WriteLine(s); ;
    }

    static int[] OneAns = new int[] { 0, 1, 2, 3, 3, 4, 5, 6, 7, 7, };
    static long CountAll(long x)
    {
        if (x < OneAns.Length)
            return OneAns[x];

        MaxNKeta = x.ToString().Length;
        EachDigit = x.ToString().Select(n => (int)(n - '0')).ToArray();
        var c = F(0, false);
        return c - 1; // remove 0
    }

    static int[] EachDigit;
    static int MaxNKeta;

    static long F(int depth, bool upperIsHigh)
    {
        if (depth == MaxNKeta)
            return 1;
        if (upperIsHigh)
        {
            return (long)Math.Pow(8, MaxNKeta - depth);
        }
        switch (EachDigit[depth])
        {
            case 9:
                return 8 * F(depth + 1, true);
            case 8:
                return 1 * F(depth + 1, false)
                     + 7 * F(depth + 1, true);
            case 7:
                return 1 * F(depth + 1, false)
                     + 6 * F(depth + 1, true);
            case 6:
                return 1 * F(depth + 1, false)
                     + 5 * F(depth + 1, true);
            case 5:
                return 1 * F(depth + 1, false)
                     + 4 * F(depth + 1, true);
            case 4:
                return 4 * F(depth + 1, true);
            case 3:
                return 1 * F(depth + 1, false)
                     + 3 * F(depth + 1, true);
            case 2:
                return 1 * F(depth + 1, false)
                     + 2 * F(depth + 1, true);
            case 1:
                return 1 * F(depth + 1, false)
                     + 1 * F(depth + 1, true);
            case 0:
                return 1 * F(depth + 1, false);
        }
        throw new Exception();
    }
}

public static class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}