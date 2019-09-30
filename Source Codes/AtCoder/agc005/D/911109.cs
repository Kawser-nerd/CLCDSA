using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly int Mod = 924844033;
    static void Add(ref int a, int b) { if ((a += b) >= Mod) a -= Mod; }
    static void Add(ref long a, long b) { if ((a += b) >= Mod) a -= Mod; }

    public void Solve()
    {
        int N = Reader.Int(), K = Reader.Int();
        int M = Math.Min(N, 2 * K);
        var all = new long[N + 1];
        all[0] = 1;

        for (int i = 0; i < M; i++)
        {
            var curr = DP(i, N, K);
            var nextAll = new long[N + 1];
            for (int v = N; v >= 0; v--)
                if (all[v] > 0)
                    for (int add = curr.Length - 1; add >= 0; add--)
                        if (curr[add] > 0 && v + add <= N)
                            Add(ref nextAll[v + add], all[v] * curr[add] % Mod);
            all = nextAll;
        }
        long ans = 0, fact = 1;
        for (int i = 0; i <= N; i++, fact = fact * i % Mod)
            ans += all[N - i] * fact * ((N - i) % 2 == 0 ? 1 : -1) % Mod;
        ans = (ans % Mod + Mod) % Mod;

        Console.WriteLine(ans);
    }

    int[] DP(int start, int Width, int K)
    {
        int len = (Width - start + K * 2 - 1) / (K * 2);
        int last = start + len * K * 2 - K;
        var dp = new int[len + 1, len + 1, 2];
        dp[0, 0, 0] = 1;

        for (int i = 0; i < len; i++)
            for (int sum = 0; sum <= i; sum++)
                for (int used = 0; used < 2; used++)
                    if (dp[i, sum, used] > 0)
                    {
                        int val = dp[i, sum, used];
                        Add(ref dp[i + 1, sum, 0], val);
                        if (used == 0 && (i > 0 || start >= K))
                            Add(ref dp[i + 1, sum + 1, 0], val);
                        if (i + 1 < len || last < Width)
                            Add(ref dp[i + 1, sum + 1, 1], val);
                    }
        var res = new int[len + 1];
        for (int sum = 0; sum <= len; sum++)
            res[sum] = (dp[len, sum, 0] + dp[len, sum, 1]) % Mod;

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