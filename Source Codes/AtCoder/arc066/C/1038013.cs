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
    static readonly long INF = (long)1e18;
    static readonly int[] Sign = { 1, -1, 1 };

    public void Solve()
    {
        int N = Reader.Int();
        var S = Reader.StringArray(N * 2 - 1);
        var A = S.Where((v, i) => i % 2 == 0).Select(s => long.Parse(s)).ToArray();
        var op = new[] { "+" }.Concat(S.Where((v, i) => i % 2 == 1)).ToArray();
        var dp = new long[N + 1, 3];
        Fill(dp, -INF);
        dp[0, 0] = 0;

        for (int i = 0; i < N; i++)
            for (int open = 0; open <= 2; open++)
                if (dp[i, open] > -INF)
                    if (op[i] == "+")
                    {
                        int nopen = Math.Max(0, open - 1);
                        CheckMax(ref dp[i + 1, open], dp[i, open] + A[i] * Sign[open]);
                        CheckMax(ref dp[i + 1, nopen], dp[i, open] + A[i] * Sign[nopen]);
                    }
                    else
                    {
                        int nopen = Math.Min(2, open + 1);
                        CheckMax(ref dp[i + 1, nopen], dp[i, open] + A[i] * Sign[nopen]);
                    }

        Console.WriteLine(Math.Max(dp[N, 0], Math.Max(dp[N, 1], dp[N, 2])));
    }

    bool CheckMax(ref long a, long b) { if (b > a) { a = b; return true; } return false; }

    void Fill<T>(T[,] A, T val)
    {
        for (int a = 0; a < A.GetLength(0); a++)
            for (int b = 0; b < A.GetLength(1); b++)
                A[a, b] = val;
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