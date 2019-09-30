using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly int Mod = (int)1e9 + 7;

    public void Solve()
    {
        int N = Reader.Int();
        int[] X = new int[N], V = new int[N];
        for (int i = 0; i < N; i++) { X[i] = Reader.Int(); V[i] = Reader.Int(); }
        V = Compress(V);
        Array.Sort(X, V);
        int[] L = new int[N], R = new int[N];

        for (int i = 0, max = -1; i < N; i++)
            R[i] = max = Math.Max(max, V[i] + 1);
        for (int i = N - 1, min = int.MaxValue; i >= 0; i--)
            L[i] = min = Math.Min(min, V[i]);

        var BIT = new BinaryIndexedTree(N + 1, Mod);
        BIT.Add(0, 1);
        for (int i = 0; i < N; i++)
            BIT.Add(R[i], BIT.Sum(L[i], R[i] + 1));

        Console.WriteLine(BIT.Sum(N, N + 1));
    }

    int[] Compress<T>(T[] A)
    {
        var sortedSet = new SortedSet<T>();
        foreach (var a in A) sortedSet.Add(a);
        var sorted = sortedSet.ToArray();
        var res = new int[A.Length];
        for (int i = 0; i < A.Length; i++) res[i] = Array.BinarySearch(sorted, A[i]);
        return res;
    }
}

class BinaryIndexedTree
{
    private readonly int N;
    private readonly int Mod;
    private readonly int[] A;

    public BinaryIndexedTree(int N, int mod)
    {
        this.N = N + 1;
        Mod = mod;
        A = new int[N + 2];
    }
    public void Add(int i, int val)
    {
        if (i < 0) return;
        for (++i; i <= N; i += i & -i) ModAdd(ref A[i], val);
    }
    public int Sum(int i) // [0, i]
    {
        if (i < 0) return 0;
        int sum = 0;
        for (++i; i > 0; i &= i - 1) ModAdd(ref sum, A[i]);
        return sum;
    }
    public int Sum(int L, int R) // [L, R)
    {
        return (Sum(R - 1) - Sum(L - 1) + Mod) % Mod;
    }
    void ModAdd(ref int a, int b) { a += b; if (a >= Mod) a -= Mod; }
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