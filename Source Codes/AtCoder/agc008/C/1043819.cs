using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        var A = Reader.IntLine();
        long atmost = Math.Min(A[0], Math.Min(A[3], A[4]));
        long L = 0, R = atmost;

        while (R - L > 3)
        {
            long x1 = L + (R - L) / 3;
            long x2 = L + (R - L) / 3 * 2;
            long fx1 = F(x1, A[0], A[3], A[4]);
            long fx2 = F(x2, A[0], A[3], A[4]);
            if (fx1 < fx2) L = x1;
            else R = x2;
        }
        long ans = 0;
        for (long x = Math.Max(0, L - 10); x <= Math.Min(atmost, L + 10); x++)
            ans = Math.Max(ans, F(x, A[0], A[3], A[4]));
        ans += A[1] * 2L;

        Console.WriteLine(ans / 2);
    }

    long F(long use, long a, long b, long c)
    {
        long res = use * 6L;
        res += (a - use) / 2L * 4;
        res += (b - use) / 2L * 4;
        res += (c - use) / 2L * 4;
        return res;
    }
}


class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    static TextReader reader = Console.In;
    static readonly char[] separator = { ' ' };
    static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    static string[] A = new string[0];
    static int i;
    static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Range(N, Int); }
    public static int[][] IntTable(int H) { return Range(H, IntLine); }
    public static string[] StringArray(int N) { return Range(N, Next); }
    public static string[][] StringTable(int N) { return Range(N, () => Split(Line())); }
    public static string Line() { return reader.ReadLine().Trim(); }
    public static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    static string[] Split(string s) { return s.Split(separator, op); }
    static string Next() { CheckNext(); return A[i++]; }
    static bool CheckNext()
    {
        if (i < A.Length) return true;
        string line = reader.ReadLine();
        if (line == null) return false;
        if (line == "") return CheckNext();
        A = Split(line);
        i = 0;
        return true;
    }
}