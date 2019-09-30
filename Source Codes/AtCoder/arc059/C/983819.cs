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
    static void Add(ref long a, long b) { if ((a += b) >= Mod) a -= Mod; }

    public void Solve()
    {
        int N = Reader.Int(), C = Reader.Int();
        var A = Reader.IntArray(N);
        var B = Reader.IntArray(N);

        int Bmax = B.Max();
        var powSum = new long[Bmax + 1, C + 1];
        for (int x = 1; x <= Bmax; x++)
            for (long n = 0, p = 1; n <= C; n++, p = p * x % Mod)
                powSum[x, n] = (powSum[x - 1, n] + p) % Mod;

        var dp = new long[C + 1];
        dp[0] = 1;
        for (int i = 0; i < N; i++)
        {
            var nextdp = new long[C + 1];
            for (int sum = 0; sum <= C; sum++)
                for (int add = 0; sum + add <= C; add++)
                {
                    long v = (Mod + powSum[B[i], add] - powSum[A[i] - 1, add]) % Mod;
                    Add(ref nextdp[sum + add], v * dp[sum] % Mod);
                }
            dp = nextdp;
        }

        Console.WriteLine(dp[C] % Mod);
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