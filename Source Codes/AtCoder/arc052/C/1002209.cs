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
    static readonly int INF = (int)1e9;
    int N, M;
    int[][] E1, E2;
    int[] MinCost;
    MinHeap heap = new MinHeap();

    public void Solve()
    {
        ReadEdges(N = Reader.Int(), M = Reader.Int());
        MinCost = new int[N];
        for (int i = 1; i < N; i++) MinCost[i] = INF;
        heap.Push(0);

        while (heap.Count > 0)
        {
            var key = heap.Pop();
            int a, used, cost;
            Decompress(key, out a, out used, out cost);
            if (cost > MinCost[a]) continue;
            MinCost[a] = cost;
            foreach (int b in E1[a]) Update(b, used, cost + 1);
            foreach (int b in E2[a]) Update(b, used + 1, cost + used + 1);
        }

        Console.WriteLine(string.Join("\n", MinCost));
    }

    void Update(int v, int used, int cost)
    {
        if (cost < MinCost[v]) heap.Push(Compress(v, used, cost));
    }
    long Compress(long v, long used, long cost)
    {
        return (used << 48) + (cost << 16) + v;
    }
    void Decompress(long key, out int v, out int used, out int cost)
    {
        used = (int)(key >> 48); cost = (int)(key >> 16); v = (int)(key & 0xffff);
    }

    void ReadEdges(int N, int M)
    {
        var e1 = Enu.Range(0, N).Select(i => new List<int>()).ToArray();
        var e2 = Enu.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < M; i++)
        {
            int type = Reader.Int(), a = Reader.Int(), b = Reader.Int();
            if (type == 0) { e1[a].Add(b); e1[b].Add(a); }
            else { e2[a].Add(b); e2[b].Add(a); }
        }
        E1 = e1.Select(e => e.ToArray()).ToArray();
        E2 = e2.Select(e => e.ToArray()).ToArray();
    }
}

class MinHeap
{
    const int InitialSize = 1024;
    long[] A = new long[InitialSize];

    public int Count { get; private set; }
    public long Peek() { return A[0]; }
    public bool Empty() { return Count == 0; }

    public void Push(long val)
    {
        if (Count == A.Length)
        {
            long[] next = new long[A.Length * 2];
            Array.Copy(A, next, A.Length);
            A = next;
        }
        A[Count++] = val;
        int i = Count - 1;
        while (i > 0)
        {
            int parent = i - 1 >> 1;
            if (val < A[parent]) { A[i] = A[parent]; i = parent; }
            else break;
        }
        A[i] = val;
    }

    public long Pop()
    {
        long res = A[0];
        long val = A[--Count];
        if (Count == 0) return res;
        int i = 0;
        while (i * 2 + 1 < Count)
        {
            int L = (i << 1) + 1;
            int R = (i << 1) + 2;
            if (R < Count && A[R] < A[L]) L = R;
            if (A[L] <= val) { A[i] = A[L]; i = L; }
            else break;
        }
        A[i] = val;
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