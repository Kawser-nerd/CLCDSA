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
        int N = Reader.Int();
        var table = new int[1][].Concat(Reader.IntTable(N - 1)).ToArray();
        var seg = new MinSegTree(N, -1);
        seg.Set(0, 0);
        int grundy = 0;

        for (int i = 1; i < N; i++)
        {
            int L = i - table[i][0], num = table[i][1];
            int g = BinarySearchMax(0, N - 1, x => seg.Min(0, x) >= L);
            seg.Set(g, i);
            if (num % 2 == 1) grundy ^= g;
        }

        Console.WriteLine(grundy == 0 ? "Second" : "First");
    }
    
    // [L, R]
    int BinarySearchMax(int L, int R, Predicate<int> F)
    {
        R++;
        for (int x; R - L > 1; )
            if (F((x = L + R >> 1))) L = x;
            else R = x;
        return L;
    }
}

class MinSegTree
{
    static readonly long[] Q = new long[100];
    public readonly int N;
    readonly int[] Val;

    public MinSegTree(int n, int initialVal = int.MaxValue)
    {
        for (N = 2; N < n; ) N *= 2;
        Val = new int[N * 2];
        for (int i = 0; i < Val.Length; i++) Val[i] = initialVal;
    }
    public MinSegTree(int[] A)
    {
        for (N = 2; N < A.Length; ) N *= 2;
        Val = new int[N * 2];
        for (int i = 0; i <= N; i++)
            Val[N - 1 + i] = (i < A.Length) ? A[i] : int.MaxValue;
        for (int i = N - 2; i >= 0; i--)
            Val[i] = Math.Min(Val[(i << 1) + 1], Val[(i << 1) + 2]);
    }

    public void Set(int index, int val)
    {
        index += N - 1;
        Val[index] = val;
        for (int i = index - 1 >> 1; i >= 0; i = i - 1 >> 1)
            Val[i] = Math.Min(Val[(i << 1) + 1], Val[(i << 1) + 2]);
    }

    public int Min(int L = 0, int R = int.MaxValue)
    {
        int res = int.MaxValue;
        Q[0] = 0;
        for (int s = 0, t = 1, len = N, first = 1; s != t; ++s)
        {
            int i = (int)(Q[s] >> 32), a = (int)Q[s];
            if (s == first) { len >>= 1; first = t; }
            if (a >= L && a + len <= R) { res = Math.Min(res, Val[i]); continue; }
            if (Val[i] >= res) continue;
            int mid = a + (len >> 1);
            if (L < mid) Q[t++] = ((long)(i << 1) + 1 << 32) + a;
            if (R > mid) Q[t++] = ((long)(i << 1) + 2 << 32) + mid;
        }
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