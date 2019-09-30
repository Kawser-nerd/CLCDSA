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

    public void Solve()
    {
        int N = Reader.Int();
        var A = Reader.IntArray(N);
        Console.WriteLine(Calc(N, A));
    }

    private long Calc(int N, int[] A)
    {
        long ans = 1;
        var count = new int[N];
        foreach (int a in A) count[a]++;
        if (N % 2 == 0 && count[0] > 0) return 0;
        if (N % 2 == 1 && count[0] != 1) return 0;
        for (int i = 1; i < N; i++)
        {
            if (i % 2 == N % 2 && count[i] > 0) return 0;
            if (i % 2 != N % 2 && count[i] != 2) return 0;
            if (i % 2 != N % 2 && count[i] == 2) ans = ans * 2 % Mod;
        }
        return ans;
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