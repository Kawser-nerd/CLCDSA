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
    int N;
    double?[, ,] memo;

    public void Solve()
    {
        N = Reader.Int();
        int K = Reader.Int();
        memo = new double?[N + 1, K + 1, 2];
        Console.WriteLine(Rec(N, K, 0));
    }

    private double Rec(int rem, int K, int ateMax)
    {
        if (rem == 0) return ateMax;
        if (memo[rem, K, ateMax].HasValue) return memo[rem, K, ateMax].Value;

        double L = 1.0 / (N - rem + 1);
        double res = (1 - L) * Rec(rem - 1, K, ateMax);
        double a = (K == 0) ? 0 : Rec(rem - 1, K - 1, 1);
        double b = Rec(rem - 1, K, 0);
        res += L * Math.Max(a, b);

        memo[rem, K, ateMax] = res;

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