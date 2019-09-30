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
        int N = Reader.Int(), K = Reader.Int();
        var V = Reader.IntTable(N);
        var SetV = new int[1 << N];

        for (int mask = 0; mask < (1 << N); mask++)
            for (int a = 0; a < N; a++)
                if ((mask >> a & 1) == 1)
                    for (int b = 0; b < a; b++)
                        if ((mask >> b & 1) == 1)
                            SetV[mask] += V[a][b];
        var dp = new int[1 << N];
        for (int mask = 1; mask < (1 << N); mask++)
            for (int sub = mask; sub > 0; sub = sub - 1 & mask)
                CheckMax(ref dp[mask], dp[mask - sub] + SetV[sub] + K);

        Console.WriteLine(dp[(1 << N) - 1] - SetV[(1 << N) - 1]);
    }

    bool CheckMax(ref int a, int b) { if (b > a) { a = b; return true; } return false; }
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
    static T[] Range<T>(int N, Func<T> f) { return Enu.Range(0, N).Select(i => f()).ToArray(); }
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