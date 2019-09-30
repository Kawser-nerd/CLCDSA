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
    long[] count, index;

    public void Solve()
    {
        int N = Reader.Int(), Mult = Reader.Int(), K = Reader.Int();
        var A = Reader.IntArray(N);
        double L = 0, R = 1e11;
        count = new long[N];
        index = new long[N];

        for (int t = 0; t < 200; t++)
        {
            double mid = (L + R) / 2;
            if (Calc(mid, A, Mult) >= K) R = mid;
            else L = mid;
        }
        Calc(R, A, Mult, true);
        foreach (int i in index)
            Console.WriteLine(A[i] * ModPower(Mult, count[i], Mod) % Mod);
        Console.ReadLine();
    }

    private long Calc(double lastMin, int[] A, long Mult, bool sort = false)
    {
        int N = A.Length;
        long sum = 0;
        var last = new double[N];
        for (int i = 0; i < N; i++) index[i] = i;
        double logMult = Math.Log(Mult);

        for (int i = 0; i < N; i++)
        {
            double logA = Math.Log(A[i]);
            // logA + pow * logMult >= lastMin
            long pow = Math.Max(0, (long)Math.Ceiling((lastMin - logA) / logMult));
            sum += count[i] = pow;
            last[i] = logA + pow * Math.Log(Mult);
        }
        if (sort) Array.Sort(last, index);

        return sum;
    }

    long ModPower(long x, long n, long mod) // x ^ n
    {
        long res = 1;
        if ((x %= mod) < 0) x += mod;
        for (; n > 0; n >>= 1, x = x * x % mod)
            if ((n & 1) == 1) res = res * x % mod;
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