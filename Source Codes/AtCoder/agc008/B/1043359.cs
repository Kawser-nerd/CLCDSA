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
    static readonly long INF = (long)1e15;

    public void Solve()
    {
        int N = Reader.Int(), K = Reader.Int();
        var A = Reader.IntArray(N);
        var sum = new long[N + 1];
        for (int i = 0; i < N; i++) sum[i + 1] = sum[i] + A[i];
        var dp = new long[N + 1, 2];
        Fill(dp, -INF);
        dp[0, 0] = 0;

        for (int i = 0; i < N; i++)
            for (int b = 0; b < 2; b++)
            {
                var val = dp[i, b];
                CheckMax(ref dp[i + 1, 0], val);
                if (b == 1) CheckMax(ref dp[i + 1, 1], val + Math.Max(0, A[i]));
                if (i + K <= N)
                {
                    if (i + K + 1 <= N) CheckMax(ref dp[i + 1, 0], val + A[i]);
                    CheckMax(ref dp[i + K, 1], val);
                    CheckMax(ref dp[i + K, 1], val + sum[i + K] - sum[i]);
                }
            }

        Console.WriteLine(Math.Max(dp[N, 0], dp[N, 1]));
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