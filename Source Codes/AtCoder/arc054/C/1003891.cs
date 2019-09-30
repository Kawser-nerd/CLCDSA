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
        var S = Reader.StringArray(N);
        var M = new BinaryMatrix(N, N);
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                M[r, c] = S[r][c] - '0';
        Console.WriteLine(M.GaussJordan(N) < N ? "Even" : "Odd");
    }
}

class BinaryMatrix
{
    private readonly long[][] M;

    public BinaryMatrix(int H, int W)
    {
        M = new long[H][];
        for (int i = 0; i < H; i++) M[i] = new long[(W + 63) / 64];
    }
    public long this[int r, int c]
    {
        get { return M[r][c >> 6] >> c & 1; }
        set { if (value == 0) M[r][c >> 6] &= ~(1L << c); else M[r][c >> 6] |= 1L << c; }
    }
    public int GaussJordan(int W)
    {
        int rank = 0;
        for (int c = 0; c < W; c++)
        {
            int r = Array.FindIndex(M, rank, a => (a[c >> 6] >> c & 1) == 1);
            if (r < 0) continue;
            var t = M[rank]; M[rank] = M[r]; M[r] = t;
            for (r = rank + 1; r < M.Length; r++)
                if ((M[r][c >> 6] >> c & 1) == 1)
                    for (int x = 0; x < M[r].Length; x++)
                        M[r][x] ^= M[rank][x];
            rank++;
        }
        return rank;
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