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
    int[] MinUsed, UsedAtmost, Ans;
    MinSegTree[] MinCost;
    MinHeap heap;

    public void Solve()
    {
        N = Reader.Int();
        M = Reader.Int();
        ReadEdges(N, M);
        BFS();
        InitCost();
        Dijkstra();
        Console.WriteLine(string.Join("\n", Ans));
    }

    void BFS()
    {
        MinUsed = new int[N];
        for (int i = 1; i < N; i++) MinUsed[i] = INF;
        var isIn = new bool[N];
        var q = new Queue<int>();
        q.Enqueue(0);
        Action<int, int> Update = (v, cost) =>
        {
            if (!CheckMin(ref MinUsed[v], cost)) return;
            if (!isIn[v]) { isIn[v] = true; q.Enqueue(v); }
        };
        while (q.Count > 0)
        {
            int a = q.Dequeue();
            int cost = MinUsed[a];
            isIn[a] = false;
            foreach (int b in E1[a]) Update(b, cost);
            foreach (int b in E2[a]) Update(b, cost + 1);
        }
    }

    void InitCost()
    {
        MinCost = new MinSegTree[N];
        MinCost[0] = new MinSegTree(1);
        MinCost[0].Set(0, 0);
        UsedAtmost = new int[N];

        for (int i = 1; i < N; i++)
        {
            int x = MinUsed[i], cost = N - x + x * (x + 1) / 2;
            int atmost = MinUsed[i];
            for (int bit = 1 << 14; bit > 0; bit >>= 1)
                if ((x = atmost + bit) < N && x * (x + 1) / 2 <= cost)
                    atmost += bit;
            UsedAtmost[i] = atmost;
            MinCost[i] = new MinSegTree(atmost - MinUsed[i] + 1);
        }
    }

    void Dijkstra()
    {
        heap = new MinHeap();
        heap.Push(0);
        while (heap.Count > 0)
        {
            var key = heap.Pop();
            int a, used, cost;
            Decompress(key, out a, out used, out cost);
            if (cost > MinCost[a].Min(0, used - MinUsed[a] + 1)) continue;
            foreach (int b in E1[a]) Update(b, used, cost + 1);
            foreach (int b in E2[a]) Update(b, used + 1, cost + used + 1);
        }
        Ans = new int[N];
        for (int i = 0; i < N; i++)
            Ans[i] = MinCost[i].Min(0, MinCost[i].N);
    }

    void Update(int v, int used, int cost)
    {
        if (used <= UsedAtmost[v] && cost < MinCost[v].Min(0, used - MinUsed[v] + 1))
        {
            heap.Push(Compress(v, used, cost));
            MinCost[v].Set(used - MinUsed[v], cost);
        }
    }
    long Compress(int v, int used, int cost)
    {
        return ((long)cost << 32) + (v << 16) + used;
    }
    void Decompress(long key, out int v, out int used, out int cost)
    {
        cost = (int)(key >> 32); v = (int)(key >> 16 & 0xffff); used = (int)(key & 0xffff);
    }

    bool CheckMin(ref int a, int b) { if (b < a) { a = b; return true; } return false; }

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

class MinSegTree
{
    public static readonly int Default = (int)2e9;
    public readonly int N;
    readonly int[] Val;
    static readonly int[] Q = new int[128];

    public MinSegTree(int n)
    {
        for (N = 2; N < n; ) N *= 2;
        Val = new int[N * 2];
        for (int i = 0; i < Val.Length; i++) Val[i] = Default;
    }

    public void Set(int index, int val)
    {
        index += N - 1;
        Val[index] = val;
        while (index > 0)
        {
            index = (index - 1) >> 1;
            Val[index] = Math.Min(Val[(index << 1) + 1], Val[(index << 1) + 2]);
        }
    }

    // [L, R)
    public int Min(int L = 0, int R = -1)
    {
        if (R == -1) R = N;
        int res = Default;
        Q[0] = 0; Q[1] = 0; Q[2] = N;
        for (int QL = 0, QR = 3; QL < QR; )
        {
            int i = Q[QL++], a = Q[QL++], b = Q[QL++];
            if (a >= L && b <= R) { res = Math.Min(res, Val[i]); continue; }
            if (Val[i] >= res) continue;
            int mid = a + b >> 1;
            if (L < mid) { Q[QR++] = (i << 1) + 1; Q[QR++] = a; Q[QR++] = mid; }
            if (R > mid) { Q[QR++] = (i << 1) + 2; Q[QR++] = mid; Q[QR++] = b; }
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