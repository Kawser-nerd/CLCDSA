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
    static readonly int Mod = (int)1e9 + 7;
    static void Add(ref int a, int b) { if ((a += b) >= Mod) a -= Mod; }
    bool CheckMax(ref int a, int b) { if (b > a) { a = b; return true; } return false; }

    public void Solve()
    {
        int N = Reader.Int(), M = Reader.Int();
        var A = Reader.String().Select(c => c - '0').ToArray();
        var seg = Reader.IntTable(M);

        var R = new int[N];
        foreach (var s in seg) CheckMax(ref R[s[0] - 1], s[1]);
        for (int i = 1; i < N; i++)
            if (R[i - 1] > i) CheckMax(ref R[i], R[i - 1]);

        var sumOne = new int[N + 1]; // [0, i)
        for (int i = 0; i < N; i++)
            sumOne[i + 1] = sumOne[i] + A[i];

        var dp = new int[N + 1, N + 1];
        dp[0, 0] = 1;
        for (int i = 0; i < N; i++)
            for (int usedOne = 0; usedOne <= i; usedOne++)
                if (dp[i, usedOne] > 0)
                {
                    if (R[i] == 0)
                    {
                        Add(ref dp[i + 1, usedOne + A[i]], dp[i, usedOne]);
                        continue;
                    }
                    int remOne = sumOne[R[i]] - usedOne;
                    int remZero = (R[i] - sumOne[R[i]]) - (i - usedOne);
                    if (remOne > 0)
                        Add(ref dp[i + 1, usedOne + 1], dp[i, usedOne]);
                    if (remZero > 0)
                        Add(ref dp[i + 1, usedOne], dp[i, usedOne]);
                }

        Console.WriteLine(dp[N, sumOne[N]]);
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