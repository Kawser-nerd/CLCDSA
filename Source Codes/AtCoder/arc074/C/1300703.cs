using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    const int MaxN = 300;
    static readonly int Mod = (int)1e9 + 7;
    static void Add(ref int a, int b) { if ((a += b) >= Mod) a -= Mod; }

    public void Solve()
    {
        int N = Reader.Int(), M = Reader.Int();
        var T = Reader.IntTable(M);
        var list = Enu.Range(0, N + 1).Select(i => new List<int[]>()).ToArray();
        Array.ForEach(T, t => list[t[1]].Add(t));
        var Q = list.Select(a => a.ToArray()).ToArray();
        var dp = new int[N + 1, N + 1, N + 1];
        dp[0, 0, 0] = 1;
        int ans = 0;

        Func<int, int, int, bool> OK = (a, b, c) =>
        {
            foreach (var t in Q[c])
                if ((a >= t[0] ? 1 : 0) + (b >= t[0] ? 1 : 0) + 1 != t[2]) return false;
            return true;
        };
        for (int a = 0, val; a <= N; a++)
            for (int b = a; b <= N; b++)
                for (int c = b; c <= N; c++)
                    if ((val = dp[a, b, c]) > 0)
                    {
                        if (!OK(a, b, c)) continue;
                        if (c == N) { Add(ref ans, val); continue; }
                        Add(ref dp[a, b, c + 1], val);
                        Add(ref dp[a, c, c + 1], val);
                        Add(ref dp[b, c, c + 1], val);
                    }

        Console.WriteLine(ans);
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