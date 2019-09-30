using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;
using System.Numerics;

public class Program
{
    int N;
    int Index(int day, int good) { return day * (N + 1) + good; }
    bool CheckMax(ref long a, long b) { if (b > a) { a = b; return true; } return false; }

    public void Solve()
    {
        N = Reader.Int();
        long K = Reader.Long();
        var A = Reader.IntArray(N);
        var Sum = new long[N + 1];
        for (int i = 0; i < N; i++) Sum[i + 1] = Sum[i] + A[i];
        var dp = new long[(N + 2) * (N + 2)];
        for (int i = 1; i < dp.Length; i++) dp[i] = -1;
        dp[0] = K;

        for (int i = 0; i < N; i++)
            for (int good = 0; good <= i; good++)
            {
                long rem = dp[Index(i, good)];
                if (rem < 0) continue;
                long won = K - rem, total = Sum[i];
                long L = Math.Max(0, rem - (Sum[N] - Sum[i + 1]));
                long R = Math.Min(rem, A[i]);
                if (L <= R) CheckMax(ref dp[Index(i + 1, good)], rem - L);

                // (won + add) / (total + A[i]) > won / total
                Predicate<long> Up = add => won == 0 && add > 0 ||
                    (won + add) * total > (total + A[i]) * won;

                while (L < R)
                {
                    long mid = L + R >> 1;
                    if (Up(mid)) R = mid;
                    else L = mid + 1;
                }
                if (Up(R))
                    CheckMax(ref dp[Index(i + 1, good + 1)], rem - R);
            }

        Console.WriteLine(Enu.Range(0, N + 1).Last(i => dp[Index(N, i)] >= 0));
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