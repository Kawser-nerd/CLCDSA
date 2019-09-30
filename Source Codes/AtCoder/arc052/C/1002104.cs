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
    int[][] E1, E2, MinCost;
    int[] MinUsed, Ans;

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
        MinCost = new int[N][];
        MinCost[0] = new int[1];
        for (int i = 1; i < N; i++)
        {
            int x = MinUsed[i], cost = N - x + x * (x + 1) / 2;
            int atmost = MinUsed[i];
            for (int bit = 1 << 14; bit > 0; bit >>= 1)
                if ((x = atmost + bit) < N && x * (x + 1) / 2 <= cost)
                    atmost += bit;
            MinCost[i] = new int[atmost - MinUsed[i] + 1];
            for (int u = 0; u < MinCost[i].Length; u++)
                MinCost[i][u] = INF;
        }
    }

    void Dijkstra()
    {
        var q = new Heap<State>();
        q.Push(new State(0, 0, 0));
        Func<int, int, int> Get = (v, used) => MinCost[v][used - MinUsed[v]];
        Action<int, int, int> Update = (v, used, cost) =>
        {
            if (used - MinUsed[v] >= MinCost[v].Length) return;
            if (CheckMin(ref MinCost[v][used - MinUsed[v]], cost))
                q.Push(new State(v, used, cost));
        };

        while (q.Count > 0)
        {
            var s = q.Pop();
            int a = s.v, used = s.used, cost = s.cost;
            if (cost > Get(a, used)) continue;
            foreach (int b in E1[a]) Update(b, used, cost + 1);
            foreach (int b in E2[a]) Update(b, used + 1, cost + used + 1);
        }
        Ans = Enu.Repeat(INF, N).ToArray();
        for (int i = 0; i < N; i++)
            foreach (int v in MinCost[i])
                CheckMin(ref Ans[i], v);
    }

    struct State : IComparable<State>
    {
        public int v;
        public int used;
        public int cost;

        public State(int v, int used, int cost)
        {
            this.v = v;
            this.used = used;
            this.cost = cost;
        }
        public int CompareTo(State other)
        {
            return cost - other.cost;
        }
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

class Heap<T>
{
    private const int InitialSize = 1024;
    private readonly int sign;
    private readonly Comparer<T> comp = Comparer<T>.Default;
    private T[] A = new T[InitialSize];
    public int Count { get; private set; }
    public Heap(bool greater = false) { sign = greater ? 1 : -1; }
    public T Peek() { return A[0]; }
    public bool Empty() { return Count == 0; }
    public void Push(T val)
    {
        if (Count == A.Length)
        {
            T[] next = new T[A.Length * 2];
            Array.Copy(A, next, A.Length);
            A = next;
        }
        A[Count++] = val;
        int i = Count - 1;
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (Math.Sign(comp.Compare(val, A[parent])) == sign)
            {
                A[i] = A[parent];
                i = parent;
            }
            else break;
        }
        A[i] = val;
    }
    public T Pop()
    {
        T res = A[0];
        T val = A[--Count];
        if (Count == 0) return res;
        int i = 0;
        while (i * 2 + 1 < Count)
        {
            int L = i * 2 + 1;
            int R = i * 2 + 2;
            if (R < Count && Math.Sign(comp.Compare(A[R], A[L])) == sign) L = R;
            if (Math.Sign(comp.Compare(A[L], val)) == sign) { A[i] = A[L]; i = L; }
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