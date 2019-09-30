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
        int N = Reader.Int(), M = Reader.Int();
        var Es = Reader.IntTable(M);
        var flow = new MinCostFlow(N);

        foreach (var e in Es)
        {
            e[0]--; e[1]--;
            flow.AddEdge(e[0], e[1], 1, e[2]);
            if (e[0] != 0) flow.AddEdge(e[1], e[0], 1, e[2]);
        }
        int ans = MinCostFlow.INF;
        for (int a = 1; a < N; a++)
            ans = Math.Min(ans, flow.Run(0, a, 2, ans));
        if (ans == MinCostFlow.INF) ans = -1;
        Console.WriteLine(ans);
    }
}


public class MinCostFlow
{
    public const int INF = (int)1e9;
    int NumV, S, T;
    int[] NumE, PrevV, PrevE;
    int[] Potential, MinCost;
    int[][] To, ReverseE;
    int[][] Capacity, InitCapacity, Cost;
    bool firstRun = true;

    public MinCostFlow(int numV)
    {
        NumV = numV;
        PrevV = new int[numV];
        PrevE = new int[numV];
        NumE = new int[numV];
        Potential = new int[numV];
        MinCost = new int[numV];
        To = new int[numV][];
        ReverseE = new int[numV][];
        Capacity = new int[numV][];
        InitCapacity = new int[numV][];
        Cost = new int[numV][];
        for (int v = 0; v < numV; v++)
        {
            To[v] = new int[1];
            ReverseE[v] = new int[1];
            Capacity[v] = new int[1];
            InitCapacity[v] = new int[1];
            Cost[v] = new int[1];
        }
    }

    public void AddEdge(int from, int to, int capacity, int cost)
    {
        int A = from, B = to, ai = NumE[A]++, bi = NumE[B]++;
        if (ai == To[A].Length) DoubleArrays(A);
        if (bi == To[B].Length) DoubleArrays(B);
        To[A][ai] = B; ReverseE[A][ai] = bi; Cost[A][ai] = cost; Capacity[A][ai] = InitCapacity[A][ai] = capacity;
        To[B][bi] = A; ReverseE[B][bi] = ai; Cost[B][bi] = -cost; Capacity[B][bi] = InitCapacity[B][bi] = 0;
    }

    public int Run(int s, int t, int flow, int inf = INF)
    {
        S = s;
        T = t;
        int sumCost = 0;
        if (!firstRun) Init();
        firstRun = false;
        while (flow > 0)
        {
            ShortestPath(inf);
            if (MinCost[T] == inf) return INF;
            for (int i = 0; i < NumV; i++)
                if (MinCost[i] < INF) Potential[i] += MinCost[i];
            int f = flow;
            for (int v = T; v != S; v = PrevV[v])
                f = Math.Min(f, Capacity[PrevV[v]][PrevE[v]]);
            flow -= f;
            sumCost += f * Potential[T];
            for (int v = T; v != S; v = PrevV[v])
            {
                Capacity[PrevV[v]][PrevE[v]] -= f;
                Capacity[v][ReverseE[PrevV[v]][PrevE[v]]] += f;
            }
        }
        return sumCost;
    }

    public void Init()
    {
        Array.Clear(Potential, 0, Potential.Length);
        for (int v = 0; v < NumV; v++)
            for (int e = 0; e < NumE[v]; e++)
                Capacity[v][e] = InitCapacity[v][e];
    }

    void DoubleArrays(int i)
    {
        int size = To[i].Length * 2;
        Array.Resize(ref To[i], size);
        Array.Resize(ref ReverseE[i], size);
        Array.Resize(ref Cost[i], size);
        Array.Resize(ref Capacity[i], size);
        Array.Resize(ref InitCapacity[i], size);
    }

    void ShortestPath(int inf)
    {
        for (int i = 0; i < NumV; i++) MinCost[i] = inf;
        MinCost[S] = 0;
        var heap = new Heap();
        heap.Push(S);
        while (heap.Count > 0)
        {
            long mask = heap.Pop();
            int currCost = (int)(mask >> 32);
            int v = (int)mask;
            if (currCost > Math.Min(Potential[v] + MinCost[v], Potential[T] + MinCost[T])) continue;
            for (int ei = 0; ei < NumE[v]; ei++)
                if (Capacity[v][ei] > 0)
                {
                    int to = To[v][ei];
                    int nextCost = currCost + Cost[v][ei] - Potential[to];
                    if (nextCost < MinCost[to])
                    {
                        MinCost[to] = nextCost;
                        PrevV[to] = v;
                        PrevE[to] = ei;
                        heap.Push(((long)(nextCost + Potential[to]) << 32) + to);
                    }
                }
        }
    }
}

public class Heap
{
    const int InitialSize = 1000;
    long[] A = new long[InitialSize];

    public int Count { get; private set; }
    public long Peek() { return A[1]; }
    public bool Empty() { return Count == 0; }

    public void Push(long val)
    {
        int i = ++Count;
        if (i == A.Length) Array.Resize(ref A, A.Length * 2);
        for (; i > 1 && val < A[i >> 1]; i >>= 1) A[i] = A[i >> 1];
        A[i] = val;
    }

    public long Pop()
    {
        long res = A[1];
        long val = A[Count--];
        if (Count == 0) return res;
        int i = 1;
        for (int L = i << 1, R = L | 1; L <= Count; L = i << 1, R = L | 1)
            if (R <= Count && A[R] < A[L] && A[R] < val) { A[i] = A[R]; i = R; }
            else if (A[L] < val) { A[i] = A[L]; i = L; }
            else break;
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