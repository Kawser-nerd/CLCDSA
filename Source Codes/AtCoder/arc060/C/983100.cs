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
        int N = Reader.Int();
        var X = Reader.IntArray(N);
        int L = Reader.Int(), Q = Reader.Int();
        var table = Reader.IntTable(Q);

        int logN = 0;
        while ((1 << logN + 1) <= N - 1) logN++;
        var next = new int[logN + 1][];
        for (int i = 0; i <= logN; i++)
            next[i] = new int[N];
        for (int i = 0; i < N; i++)
            next[0][i] = UpperBound(X, X[i] + L) - 1;
        for (int p = 0; p < logN; p++)
            for (int i = 0; i < N; i++)
                next[p + 1][i] = next[p][next[p][i]];

        var ans = new int[Q];
        for (int qi = 0; qi < Q; qi++)
        {
            int a = table[qi][0] - 1, b = table[qi][1] - 1;
            if (a > b) Swap(ref a, ref b);
            for (int p = logN; p >= 0; p--)
                if (next[p][a] < b)
                {
                    ans[qi] += 1 << p;
                    a = next[p][a];
                }
            ans[qi]++;
        }

        Console.WriteLine(string.Join("\n", ans));
    }

    static void Swap<T>(ref T a, ref T b) { T t = a; a = b; b = t; }

    static int UpperBound(int[] A, int val, int L = 0, int R = -1)
    {
        if (R == -1) R = A.Length;
        while (R - L >= 1)
        {
            int mid = (L + R) / 2;
            if (A[mid] > val) R = mid;
            else L = mid + 1;
        }
        return R;
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