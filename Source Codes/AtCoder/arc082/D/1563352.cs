using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        int S = Reader.Int(), N = Reader.Int();
        var R = Reader.IntArray(N);
        int NQ = Reader.Int();
        var Q = Reader.IntTable(NQ);
        var diff = new long[N + 1];
        long[] min = new long[N + 1], max = new long[N + 1];
        long[] lower = new long[N + 1], upper = new long[N + 1];
        min[0] = 0;
        max[0] = S;
        upper[0] = S;

        for (int i = 0; i < N; i++)
        {
            int r = R[i] - (i == 0 ? 0 : R[i - 1]);
            diff[i + 1] = diff[i] + (i % 2 == 0 ? -r : r);
            if (i % 2 == 0)
            {
                min[i + 1] = Math.Max(min[i], r - diff[i]);
                max[i + 1] = max[i];
                lower[i + 1] = Math.Max(0, lower[i] - r);
                upper[i + 1] = Math.Max(0, upper[i] - r);
            }
            else
            {
                min[i + 1] = min[i];
                max[i + 1] = Math.Min(max[i], S - r - diff[i]);
                lower[i + 1] = Math.Min(S, lower[i] + r);
                upper[i + 1] = Math.Min(S, upper[i] + r);
            }
        }
        var ans = new List<long>();
        foreach (var q in Q)
        {
            int time = q[0];
            long x = q[1];
            int i = UpperBound(R, time) - 1;
            if (i == -1) { ans.Add(Math.Max(0, x - time)); continue; }
            if (x >= min[i + 1] && x <= max[i + 1]) x += diff[i + 1];
            else if (x < min[i + 1]) x = lower[i + 1];
            else x = upper[i + 1];
            if (i % 2 == 0) x = Math.Min(S, x + (time - R[i]));
            else x = Math.Max(0, x - (time - R[i]));
            ans.Add(x);
        }

        Console.WriteLine(string.Join("\n", ans));
    }

    bool CheckMin(ref int a, int b) { if (b < a) { a = b; return true; } return false; }
    bool CheckMax(ref int a, int b) { if (b > a) { a = b; return true; } return false; }

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