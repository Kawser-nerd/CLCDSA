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
        long A = Reader.Long(), B = Reader.Long();
        if (A == B) { Console.WriteLine(1); return; }
        int at = Enu.Range(0, 60).Last(i => (A >> i & 1) != (B >> i & 1));
        long X = 1L << at;
        A &= (X << 1) - 1;
        B &= (X << 1) - 1;
        long Bmax = X + (1L << Enu.Range(1, at).LastOrDefault(i => (B >> i - 1 & 1) == 1));
        long[] L = new long[3], R = new long[3];
        L[0] = A; R[0] = X;
        L[1] = X; R[1] = Bmax;
        L[2] = X + A; R[2] = X << 1;
        Console.WriteLine(SumLen(L, R));
    }

    long SumLen(long[] L, long[] R)
    {
        var P = new long[L.Length * 2];
        for (int i = 0; i < L.Length; i++)
        {
            P[i * 2] = L[i] << 1;
            P[i * 2 + 1] = R[i] << 1 | 1;
        }
        Array.Sort(P);
        long sum = 0, prev = P[0] >> 1, balance = 0;
        foreach (var p in P)
        {
            long x = p >> 1;
            if (balance > 0) sum += x - prev;
            balance -= ((p & 1) << 1) - 1;
            prev = x;
        }
        return sum;
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