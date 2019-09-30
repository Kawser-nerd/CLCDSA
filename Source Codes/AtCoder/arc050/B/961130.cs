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
        long R = Reader.Long(), B = Reader.Long();
        long r = Reader.Long(), b = Reader.Long();
        long atmost = Math.Min(R / r, B);
        long lb = 0, ub = atmost;

        while (ub - lb > 3)
        {
            long mid1 = lb + (ub - lb) / 3;
            long mid2 = lb + (ub - lb) / 3 * 2;
            long val1 = F(mid1, R, B, r, b);
            long val2 = F(mid2, R, B, r, b);
            if (val1 < val2) lb = mid1;
            else ub = mid2;
        }
        long ans = 0;
        for (long i = Math.Max(0, ub - 10); i <= Math.Min(atmost, ub + 10); i++)
            ans = Math.Max(ans, F(i, R, B, r, b));

        Console.WriteLine(ans);
    }

    private long F(long setA, long R, long B, long r, long b)
    {
        R -= r * setA;
        B -= setA;
        return setA + Math.Min(R, B / b);
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
    static string[] Split(string s) { return s.Split(separator, op); }
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
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