using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly int Mod = (int)1e9 + 7;
    static void Add(ref int a, int b) { if ((a += b) >= Mod) a -= Mod; }

    public void Solve()
    {
        int N = Reader.Int(), K = Reader.Int();
        var dp = new int[N * 2 + 2];

        dp[1] = 1;
        for (int A = 1; A <= N; A++)
            dp[A << 1] = 1;
        for (int i = 0, val; i < K; i++)
        {
            var nextdp = new int[dp.Length];
            for (int A = 0; A <= N; A++)
                for (int seenZero = 0; seenZero < 2; seenZero++)
                    if ((val = dp[A << 1 | seenZero]) > 0)
                        for (int a1 = 0; a1 < 2; a1++)
                            if (A - a1 >= 0 && A - a1 < N)
                                for (int a2 = 0; a2 < 2; a2++)
                                {
                                    int nextSeenZero = seenZero | (A - a1 == 0 ? 1 : 0);
                                    Add(ref nextdp[A - a1 + 1 - a2 << 1 | nextSeenZero], val);
                                }
            dp = nextdp;
        }

        long ans = Enu.Range(0, N + 1).Sum(i => (long)dp[i << 1 | 1]) % Mod;
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
    static void Init() { Dispose(); A = new string[0]; }
    public static void Set(TextReader r) { Init(); reader = r; }
    public static void Set(string file) { Init(); reader = new StreamReader(file); }
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
    public static void Dispose() { reader.Dispose(); }
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