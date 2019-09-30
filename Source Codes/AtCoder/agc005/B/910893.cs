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
    public void Solve()
    {
        int N = Reader.Int();
        var A = Reader.IntArray(N);
        int[] L, R;
        Check(A, out L, out R);
        long ans = 0;
        for (int i = 0; i < N; i++)
            ans += (long)A[i] * (i - L[i] + 1) * (R[i] - i);
        Console.WriteLine(ans);
    }

    // [L, R)
    void Check(int[] H, out int[] L, out int[] R)
    {
        int N = H.Length;
        L = new int[N];
        R = new int[N];
        int[] stack = new int[N];

        for (int i = 0, si = 0; i < N; i++)
        {
            while (si > 0 && H[stack[si - 1]] >= H[i]) si--;
            L[i] = si == 0 ? 0 : stack[si - 1] + 1;
            stack[si++] = i;
        }
        for (int i = N - 1, si = 0; i >= 0; i--)
        {
            while (si > 0 && H[stack[si - 1]] >= H[i]) si--;
            R[i] = si == 0 ? N : stack[si - 1];
            stack[si++] = i;
        }
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