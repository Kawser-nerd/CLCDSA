using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    int N, M;
    int[][] E, Q;
    int[] Color;
    int[] MaxRemDist;

    public void Solve()
    {
        N = Reader.Int();
        M = Reader.Int();
        E = EdgeRead(N, M);
        int NQ = Reader.Int();
        Q = Reader.IntTable(NQ);
        foreach (var q in Q) q[0]--;
        Color = new int[N];
        MaxRemDist = Enu.Repeat(-1, N).ToArray();

        Array.Reverse(Q);
        foreach (var q in Q)
            BFS(q[0], q[1], q[2]);

        Console.WriteLine(string.Join("\n", Color));
    }

    void BFS(int start, int D, int C)
    {
        if (MaxRemDist[start] >= D) return;

        var que = new Queue<int>();
        que.Enqueue(start);
        if (MaxRemDist[start] < 0) Color[start] = C;
        MaxRemDist[start] = D;

        for (; D > 0; D--)
        {
            var nextQue = new Queue<int>();
            while (que.Count > 0)
            {
                int at = que.Dequeue();
                foreach (int next in E[at])
                    if (D - 1 > MaxRemDist[next])
                    {
                        if (MaxRemDist[next] < 0) Color[next] = C;
                        MaxRemDist[next] = Math.Max(MaxRemDist[next], D - 1);
                        nextQue.Enqueue(next);
                    }
            }
            que = nextQue;
        }
    }

    int[][] EdgeRead(int V, int E = -1, int origin = 1)
    {
        if (E == -1) E = V - 1;
        var es = new List<int>[V];
        for (int i = 0; i < V; i++) es[i] = new List<int>();
        for (int i = 0; i < E; i++)
        {
            int a = Reader.Int() - origin, b = Reader.Int() - origin;
            es[a].Add(b);
            es[b].Add(a);
        }
        return es.Select(a => a.ToArray()).ToArray();
    }
}


class RangeUpdateSumSegTree
{
    public readonly int N;
    private readonly long[] V, S;
    private readonly bool[] Flag;

    public RangeUpdateSumSegTree(int n)
    {
        for (N = 2; N < n; ) N *= 2;
        V = new long[N * 2];
        S = new long[N * 2];
        Flag = new bool[N * 2];
    }

    public long Sum(int L, int R) { return Sum(0, 0, N, L, R); }
    private long Sum(int i, int currL, int currR, int L, int R)
    {
        if (currL >= R || currR <= L) return 0;
        if (currL >= L && currR <= R) return S[i];
        if (Flag[i]) return V[i] * (Math.Min(currR, R) - Math.Max(currL, L));
        int mid = (currL + currR) / 2;
        long valL = Sum(i * 2 + 1, currL, mid, L, R);
        long valR = Sum(i * 2 + 2, mid, currR, L, R);
        return valL + valR;
    }

    public void Update(int L, int R, long val) { Update(0, val, 0, N, L, R); }
    private void Update(int i, long val, int currL, int currR, int L, int R)
    {
        if (currL >= R || currR <= L) return;
        if (currL >= L && currR <= R)
        {
            Flag[i] = true;
            V[i] = val;
            S[i] = val * (currR - currL);
            return;
        }
        if (Flag[i] && currR - currL > 1)
        {
            V[i * 2 + 1] = V[i * 2 + 2] = V[i];
            S[i * 2 + 1] = S[i * 2 + 2] = (currR - currL) / 2 * V[i];
            Flag[i * 2 + 1] = Flag[i * 2 + 2] = true;
            Flag[i] = false;
        }
        int mid = (currL + currR) / 2;
        Update(i * 2 + 1, val, currL, mid, L, R);
        Update(i * 2 + 2, val, mid, currR, L, R);
        S[i] = S[i * 2 + 1] + S[i * 2 + 2];
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